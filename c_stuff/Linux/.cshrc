set path = ( ~ ~/bin $path /usr/local/bin /usr/bin . )

set noclobber
limit coredumpsize 0

#         aliases for all shells

#alias cd            'cd \!*;set prompt="`hostname`:`pwd`>"'
alias pwd           'echo $cwd'
alias edt          'textedit -fn screen.b.14'
# JDG aliases
alias ls ls -al --color
alias labs ls -d *LAB*

set history = 1000
set savehist = 400
set ignoreeof
set prompt="%m:%~>"
# Colors!
set     red="%{\033[1;31m%}"
set   green="%{\033[0;32m%}"
set  yellow="%{\033[1;33m%}"
set    blue="%{\033[1;34m%}"
set magenta="%{\033[1;35m%}"
set    cyan="%{\033[1;36m%}"
set   white="%{\033[0;37m%}"
set     end="%{\033[0m%}" # This is needed at the end... :(

# Setting the actual prompt.  I made two separate versions for you to try, pick
# whichever one you like better, and change the colors as you want.  Just don't
# mess with the ${end} guy in either line...  Comment out or delete the prompt you don't use.

set prompt="${green}%n${blue}@%m ${yellow}%~> ${end} "
#set prompt="[${green}%n${blue}@%m ${white}%~ ]${end} "

umask 077

alias help          man
alias key           'man -k'

setenv MANPATH /usr/local/man:/usr/share/man
setenv WWW_HOME http://www.cis.temple.edu

#source ~/.aliases

# auto goto client
[ "$tty" != "" ] && [ `hostname -s` = 'CIS-Linux2' ] && exec gotoclient
