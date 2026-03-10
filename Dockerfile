FROM aflplusplus/aflplusplus
# ubuntu:22.04

RUN apt update && apt install g++ make -fy

RUN apt install libncurses-dev -fy
COPY . /workdir

WORKDIR /workdir

RUN chmod -R 777 /workdir

RUN mkdir input && cp maze.txt input

RUN make

ENV AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1
ENV AFL_SKIP_CPUFREQ=1

CMD afl-fuzz -i input/ -o output -Q -t 50000 -- ./PotterMaze @@ mybin.bin
