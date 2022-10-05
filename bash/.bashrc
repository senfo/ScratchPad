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
