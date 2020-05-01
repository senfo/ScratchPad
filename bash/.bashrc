# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# BASH Prompt
GREEN="\[$(tput setaf 2)\]"
RESET="\[$(tput sgr0)\]"
PS1="${GREEN}[\u@\h \W]\$ ${RESET}"

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
