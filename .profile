
# MacPorts Installer addition on 2011-10-21_at_19:10:00: adding an appropriate PATH variable for use with MacPorts.
export PATH=/opt/local/bin:/opt/local/sbin:$PATH
# Finished adapting your PATH environment variable for use with MacPorts.
export SSH=rmb04.homeip.net:$SSH
alias vnc_home='open vnc://rmb04.homeip.net'
alias ssh_home='ssh rmb@rmb04.homeip.net'
alias ssh_um='ssh a54770@ssh.alunos.di.uminho.pt'
export CLICOLOR=1
#alias ls='ls -Fa'
export DYLD_LIBRARY_PATH=/usr/local/instantclient:$DYLD_LIBRARY_PATH
alias phpmamp='/Applications/MAMP/bin/php/php5.3.6/bin/php'
alias phpi='/Applications/XAMPP/xamppfiles/bin/phpize'

alias ..="cd .."
alias ...="cd ../.."
alias ....="cd ../../.."

md() { mkdir -p "$@" && cd "$@"; }

export PS1="[ \w ] "

function gcc_cg {
	gcc -framework OpenGL -framework GLUT $1 -lil -g;
}

function gcc2 {
	gcc $1 -o a;
	gcc $2 -o b; 
} 