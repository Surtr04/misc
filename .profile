export CLICOLOR=1
export SSH=rmb04.homeip.net:$SSH
export PS1="[ \w ] "

alias vnc_home='open vnc://rmb04.homeip.net'
alias ssh_home='ssh rmb@rmb04.homeip.net'
alias ssh_um='ssh a54770@ssh.alunos.di.uminho.pt'
alias ..="cd .."
alias ...="cd ../.."
alias ....="cd ../../.."

md() { mkdir -p "$@" && cd "$@"; }

function gcc_cg {
	gcc -framework OpenGL -framework GLUT $1 -lil -g;
}