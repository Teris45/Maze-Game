from aflplusplus/aflplusplus
# ubuntu:22.04

run apt update && apt install g++ make -fy

RUN apt install libncurses-dev -fy
COPY . /workdir

WORKDIR /workdir
RUN mkdir input && cp maze.txt input

run make

CMD afl-fuzz -i input/ -o output -Q -t 50000 -- ./PotterMaze @@ mybin.bin
