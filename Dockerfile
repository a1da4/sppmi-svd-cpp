# image
FROM ubuntu:18.04

RUN apt-get update && \
    apt-get install -y build-essential cmake clang libssl-dev wget vim

# create workdir 'work'
RUN mkdir work

COPY ./src/ work/src/
COPY ./utils/ work/utils/

WORKDIR work

# install package Eigen:3.3.7
RUN wget https://gitlab.com/libeigen/eigen/-/archive/3.3.7/eigen-3.3.7.tar.bz2 
RUN tar vxjf eigen-3.3.7.tar.bz2
RUN mv eigen-3.3.7 /usr/local/include/

