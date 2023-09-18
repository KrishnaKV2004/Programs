#  Bash Scripting ----->

#! bin/bash

# Print Something -->

echo "Tokyo"

# Variables In Bash -->
# Uses $ To Print -->

# Untyped Variables -->
# Automatically Identifies Datatype

# Pre Defined Variables -->
# Variables Defined By The System -->

echo $HOME # Home Directory
echo $PWD # Present Working Directory
echo $BASH # Bash Shell Name
echo $BASH_VERSION #Bssh Shell Version
echo $LOGNAME # Name Of Login User

echo # Print Blank Line

# To Know About More System Variables Run env command

# User Defined Variables -->
# Variables Defined By The User -->

name = "Tokyo"
pkg = 2702

# Print Variables
echo "Name = $name"
echo "Packages = $pkg"
