# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# BASH Prompt
GREEN="\[$(tput setaf 2)\]"
RESET="\[$(tput sgr0)\]"
#PS1="${GREEN}[\u@\h \W]\$ ${RESET}"
LAST_IP_OCTET=$(ifconfig ens192 | grep 'inet' | grep -v 'inet6' | tail -1 | cut -d: -f2 | awk '{ print $2}' | sed 's/^.*\.\([^.]*\)$/\1/')
PS1="[\u@\h \W] $LAST_IP_OCTET $ "

# User specific aliases and functions
alias tableflip="echo '(╯°□°)╯︵ ┻━┻'"
alias tableback="echo '┬─┬﻿ ノ( ゜-゜ノ)'"
alias bearflip="echo 'ʕノ•ᴥ•ʔノ ︵ ┻━┻'"
alias shrug="echo '¯\_(ツ)_/¯'"
alias facepalm="echo '(－‸ლ)'"

alias ..="cd .."
alias ...="cd ../.."
alias ....="cd ../../.."
alias .....="cd ../../../.."
alias ......="cd ../../../../.."
alias fuck='sudo $(fc -ln -1)'

# Kubernetes
function evict() {
    microk8s kubectl get pods -n "$1" | grep Evicted | awk '{print $1}' | xargs microk8s kubectl delete pod -n "$1"
}

function cleanErrors() {
    microk8s kubectl get pods -n "$1" | grep Error | awk '{print $1}' | xargs microk8s kubectl delete pod -n "$1"
}

function cleanCompleted() {
    microk8s kubectl get pods -n "$1" | grep Completed | awk '{print $1}' | xargs microk8s kubectl delete pod -n "$1"
}

# SSH (be aware of security implications)
function ssh-init() {
    eval "$(ssh-agent -s)"
    ssh-add -t 1800 ~/.ssh/id_ed25519 # 30 minute timeout. Socket details stored in $SSH_AUTH_SOCK.
}

function ssh-clear() {
    ssh-add -D
}
