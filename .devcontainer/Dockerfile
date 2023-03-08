FROM ubuntu:22.10

ARG DEBIAN_FRONTEND=noninteractive
ARG PIP_INDEX_URL

RUN apt-get update && \
    apt-get install --no-install-recommends -y \
        binutils \
        build-essential \
        ccache \
        curl \
        device-tree-compiler \
        dfu-util \
        file \
        gcc \
        gcc-multilib \
        g++-multilib \
        gcc-12-multilib \
        g++-12-multilib \
        gdb \
        git \
        gperf \
        graphviz \
        libmagic1 \
        libsdl2-dev \
        locales \
        nano \
        ninja-build \
        openjdk-11-jre-headless \
        python-is-python3 \
        python3 \
        python3-pip \
        python3-setuptools \
        python3-tk \
        python3-venv \
        python3-wheel \
        ssh \
        wget \
        xz-utils \
        gnupg \
        software-properties-common \
        dotnet-sdk-6.0 && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 100 && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-12 100

RUN locale-gen en_US.UTF-8

ENV LANG en_US.UTF-8

ENV LANGUAGE en_US:en

ENV LC_ALL en_US.UTF-8

RUN python -m pip install --upgrade \
        pip \
        cmake==3.25.0 \
        west \
        conan==1.57.0 \
        ninja==1.11.1

WORKDIR /opt

RUN wget -L -O - https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.15.0/zephyr-sdk-0.15.0_linux-x86_64_minimal.tar.gz | tar -xz && \
    zephyr-sdk-0.15.0/setup.sh -t arm-zephyr-eabi -h -c

RUN useradd -ms /bin/bash zephyr

USER zephyr

ENV PATH "/home/zephyr/.local/bin:$PATH"

WORKDIR /home/zephyr

RUN wget -L -O plantuml.jar https://artifactory.hexagon.com/artifactory/gsurv-thirdparty-generic-release-local/plantuml/1.2022.13/plantuml-1.2022.13.jar
