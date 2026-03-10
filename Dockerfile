FROM aflplusplus/aflplusplus
# ubuntu:22.04

RUN apt update && apt install g++ make -fy

RUN apt install libncurses-dev -fy
COPY . /workdir

WORKDIR /workdir

RUN chmod -R 777 /workdir

RUN mkdir input && cp maze.txt input

RUN make

CMD afl-fuzz -i input/ -o output -Q -t 50000 -- ./PotterMaze @@ mybin.bin
