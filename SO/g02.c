#include <unistd.h>
#include <stdio.h>

typedef struct memBlock {
	size_t size;
	int isFree;
}MemBlock;


static int isInit = 0;
static MemBlock* init;

void use(MemBlock* block,size_t size) {

	size_t left = block->size - size - sizeof(MemBlock);
	
	
	block->isFree = 0;
	if(left > 0) {
		MemBlock *new = block + (size + sizeof(MemBlock)) / sizeof(MemBlock);
		new->size = left;
		new->isFree = 1;	
		
		block->size = size;
	}
}

int merge (MemBlock *block) {

	MemBlock *next = block + 1 + block->size / sizeof(MemBlock);

	if(next->isFree)
		block->size += next->size + sizeof(MemBlock);

	return next->isFree;	
}

void* mymalloc (size_t size) {

	if(!isInit) {
		isInit = 1;
		init = (MemBlock*)sbrk(0);
	}
	
	void* end = sbrk(0);

	if(size % sizeof(MemBlock) != 0) //alinhar bloco a sizeof(MemBlock)
		size += sizeof(MemBlock) - (size % sizeof(MemBlock));
	
	MemBlock *block = init;
	int found = 0;

	while(block != end && !found) {
		while(merge(block));
		if(block->isFree && block->size >= size)
			found = 1;
		block += (sizeof(MemBlock) + size) / sizeof(MemBlock);
	}

	if(found) {
		use(block,size);
		return block + 1;
	}

	else {
		MemBlock *new = (MemBlock*)sbrk(sizeof(MemBlock) + size);
		new->isFree = 0;
		new->size = size;
		return new + 1;
	}

}

void myfree(void *ptr) {
	MemBlock* toFree = (MemBlock*)ptr - 1; 
	toFree->isFree = 1;
	merge(toFree);
}


int main () {

	char *c;
	char *d;
	c = (char*)mymalloc(sizeof(char));
	*c = 'a';
	printf("%c\n",*c);
	myfree(c);
	
	return 0;
}
