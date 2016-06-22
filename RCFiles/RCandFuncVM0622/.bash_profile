# .bash_profile

# Get the aliases and functions
if [ -f ~/.bashrc ]; then
	. ~/.bashrc
fi

# User specific environment and startup programs

PATH=$PATH:$HOME/bin

# For GNAT (and AJIS)

      PATH=/usr/gnat/bin:$PATH
      LD_LIBRARY_PATH=/usr/gnat/lib/:$LD_LIBRARY_PATH
      CLASSPATH=/usr/gnat/lib/ajis.jar:$CLASSPATH

export PATH LD_LIBRARY_PATH CLASSPATH

