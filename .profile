# Reset
Color_Off="\[\033[0m\]"       # Text Reset

# Regular Colors
Black="\[\033[0;30m\]"        # Black
Red="\[\033[0;31m\]"          # Red
Green="\[\033[0;32m\]"        # Green
Yellow="\[\033[0;33m\]"       # Yellow
Blue="\[\033[0;34m\]"         # Blue
Purple="\[\033[0;35m\]"       # Purple
Cyan="\[\033[0;36m\]"         # Cyan
White="\[\033[0;37m\]"        # White

# Bold
BBlack="\[\033[1;30m\]"       # Black
BRed="\[\033[1;31m\]"         # Red
BGreen="\[\033[1;32m\]"       # Green
BYellow="\[\033[1;33m\]"      # Yellow
BBlue="\[\033[1;34m\]"        # Blue
BPurple="\[\033[1;35m\]"      # Purple
BCyan="\[\033[1;36m\]"        # Cyan
BWhite="\[\033[1;37m\]"       # White

# Underline
UBlack="\[\033[4;30m\]"       # Black
URed="\[\033[4;31m\]"         # Red
UGreen="\[\033[4;32m\]"       # Green
UYellow="\[\033[4;33m\]"      # Yellow
UBlue="\[\033[4;34m\]"        # Blue
UPurple="\[\033[4;35m\]"      # Purple
UCyan="\[\033[4;36m\]"        # Cyan
UWhite="\[\033[4;37m\]"       # White

# Background
On_Black="\[\033[40m\]"       # Black
On_Red="\[\033[41m\]"         # Red
On_Green="\[\033[42m\]"       # Green
On_Yellow="\[\033[43m\]"      # Yellow
On_Blue="\[\033[44m\]"        # Blue
On_Purple="\[\033[45m\]"      # Purple
On_Cyan="\[\033[46m\]"        # Cyan
On_White="\[\033[47m\]"       # White

# High Intensty
IBlack="\[\033[0;90m\]"       # Black
IRed="\[\033[0;91m\]"         # Red
IGreen="\[\033[0;92m\]"       # Green
IYellow="\[\033[0;93m\]"      # Yellow
IBlue="\[\033[0;94m\]"        # Blue
IPurple="\[\033[0;95m\]"      # Purple
ICyan="\[\033[0;96m\]"        # Cyan
IWhite="\[\033[0;97m\]"       # White

# Bold High Intensty
BIBlack="\[\033[1;90m\]"      # Black
BIRed="\[\033[1;91m\]"        # Red
BIGreen="\[\033[1;92m\]"      # Green
BIYellow="\[\033[1;93m\]"     # Yellow
BIBlue="\[\033[1;94m\]"       # Blue
BIPurple="\[\033[1;95m\]"     # Purple
BICyan="\[\033[1;96m\]"       # Cyan
BIWhite="\[\033[1;97m\]"      # White

# High Intensty backgrounds
On_IBlack="\[\033[0;100m\]"   # Black
On_IRed="\[\033[0;101m\]"     # Red
On_IGreen="\[\033[0;102m\]"   # Green
On_IYellow="\[\033[0;103m\]"  # Yellow
On_IBlue="\[\033[0;104m\]"    # Blue
On_IPurple="\[\033[10;95m\]"  # Purple
On_ICyan="\[\033[0;106m\]"    # Cyan
On_IWhite="\[\033[0;107m\]"   # White

DYLD_LIBRARY_PATH=/usr/local/cuda/lib:/usr/local/gcc-4.7.2/lib:/usr/local/Cellar/papi/lib:$DYLD_LIBRARY_PATH

export CLASSPATH=$CLASSPATH:~/.bin/jars/antlr-3.4-complete.jar

export PATH=/opt/local/bin:/opt/local/sbin:$PATH
export PATH=/usr/local/gcc-4.7.2/bin:~/.bin:~/perl5/perlbrew/perls/perl-5.16.2/bin:/usr/local/bin:/usr/texbin:/usr/local/sbin:/Developer/NVIDIA/CUDA-5.0/bin:$HOME/.rvm/bin:$PATH


#export PATH=$PATH:$HOME/.rvm/bin # Add RVM to PATH for scripting\

[[ -s "$HOME/.rvm/scripts/rvm" ]] && source "$HOME/.rvm/scripts/rvm" # Load RVM into a shell session *as a function*

#git text completion
source /usr/local/etc/bash_completion.d/git-prompt.sh
source /usr/local/etc/bash_completion.d/git-completion.bash

source ~/perl5/perlbrew/etc/bashrc

export CLICOLOR=1
export SSH=rmb04.homeip.net:$SSH

export PS1='[ '$Yellow'\w'$Color_Off'$(git branch &>/dev/null;\
if [ $? -eq 0 ]; then \
  echo "$(echo `git status` | grep "nothing to commit" > /dev/null 2>&1; \
  if [ "$?" -eq "0" ]; then \
    # @4 - Clean repository - nothing to commit
    echo "'$Green'"$(__git_ps1 " {%s}");\
  else \
    # @5 - Changes to working tree
    echo "'$IRed'"$(__git_ps1 " {%s}");\
  fi)'$BYellow$PathShort$Color_Off'";\
fi) ] '

#export PS1='[\u@\h \W$(__git_ps1 " (%s)")]\$  '

export troglodita="https://troglodita.di.uminho.pt/svn/el1213"

alias vnc_home='open vnc://rmb04.homeip.net'
alias ftp_home='ftp rmb04.homeip.net'

alias ..="cd .."
alias ...="cd ../.."
alias ....="cd ../../.."
alias grep="grep --color='auto'"
alias doc="cd ~/Documents"
alias desk="cd ~/Desktop"
alias cpd="cd ~/Documents/MEI/CPD/PI-CPD"
alias el="cd ~/Documents/MEI/EL/PI-EL"
alias htdocs="cd /Applications/MAMP/htdocs"


md() { mkdir -p "$@" && cd "$@"; }

function gcc_cg {
	gcc -framework OpenGL -framework GLUT $1 -lil -g;

}

function put_search() {	  
	scp -r "$@" cpd22781@search.di.uminho.pt:~;
}

function put_prociv() {    
  scp -r "$@" cpd22781@ie.grid.prociv.pt:~;
}

function mark() {
  if [ $# -eq 1 ]; then
    export "$1=cd `pwd`";
  fi

  if [[ $# -eq 2 && $1 = '-p' ]]; then 
    echo "$2=cd `pwd`" >> ~/.markrc;
  fi
}

function goto() {
  if [ $# -eq 1 ]; then 
    if env | grep "^$1=cd " > /dev/null; then
     a=$(env | grep "^$1=cd " | cut -d= -f2)
     eval $a;
   else
    a=$(grep "^$1=cd " ~/.markrc | cut -d= -f2)
    eval $a;
  fi

  fi
}

