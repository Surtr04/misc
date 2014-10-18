
" Added by oh-my-vim

" Change the default leader
" let mapleader = ","

" Skip upgrade of oh-my-vim itself during upgrades
" let g:ohmyvim_skip_upgrade=1

" Use :OhMyVim profiles to list all available profiles with a description
" let profiles = ['defaults', 'django', 'erl', 'friendpaste', 'git', 'makefile', 'map', 'pyramid', 'python', 'ranger', 'tmpl', 'utf8']
let profiles = ['defaults']

" Path to oh-my-vim binary (take care of it if you are using a virtualenv)
let g:ohmyvim="/Users/rmb/.oh-my-vim/env/bin/oh-my-vim"

" load oh-my-vim
source /Users/rmb/.vim/ohmyvim/ohmyvim.vim

" End of oh-my-vim required stuff

" Put your custom stuff bellow

map <C-n> :NERDTreeToggle<CR>
map <C-l> :set background=light<CR>
map <C-d> :set background=dark<CR>

let g:NERDTreeDirArrows=0

set backspace=2

let g:clang_library_path="/Library/Developer/CommandLineTools/usr/lib"

set t_Co=16
set background=dark
colorscheme solarized

set encoding=utf-8


au BufRead,BufNewFile *.tt set filetype=html
au BufRead,BufNewFile *.yp set filetype=yacc

let g:Imap_FreezeImap=1

