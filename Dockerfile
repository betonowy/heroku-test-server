FROM ubuntu:latest

COPY dconf.txt ./dconf.txt

RUN debconf-set-selections ./dconf.txt

RUN rm dconf.txt

RUN export DEBIAN_FRONTEND=noninteractive DEBCONF_NONINTERACTIVE_SEEN=true && \
    apt-get update -y && apt-get upgrade -y && \
    apt-get install -y cmake build-essential git && \
    apt-get clean

COPY drun.sh ./
COPY dsetup.sh ./

RUN ./dsetup.sh

CMD ./drun.sh

EXPOSE 13
