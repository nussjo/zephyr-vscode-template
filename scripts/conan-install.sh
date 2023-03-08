#!/bin/bash

set -ex

WORKSPACE_PATH=$1

if [[ -z "$WORKSPACE_PATH" ]]; then
    WORKSPACE_PATH=$(pwd)
fi

export CONAN_USER_HOME=${WORKSPACE_PATH}

conan install ${WORKSPACE_PATH} \
    -if ${WORKSPACE_PATH}/conan-find/x86_64-linux-gcc12 \
    -b \
    --build=gtest
