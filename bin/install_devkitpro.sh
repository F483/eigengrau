#!/bin/bash
# Copyright (c) 2015 Fabian Barkhau <fabian.barkhau@gmail.com>
# License: MIT (see LICENSE file)

# make sure user has root privileges
if [ "$(whoami)" != "root" ]; then
    echo "Error: This script must be run with root privileges!"
    exit 1
fi

# install devkitPro toolchains
BIN_DIR=$( cd $(dirname $0) ; pwd -P )
cd /tmp
perl ${BIN_DIR}/devkitARMupdate.pl
chown ${USER}:${USER} -R $(eval echo ~${SUDO_USER})/devkitPro/

