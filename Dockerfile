FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libsqlite3-dev \
    libasio-dev \
    libssl-dev

WORKDIR /app

COPY . .

RUN cmake -S . -B build
RUN cmake --build build -j4

EXPOSE 18080

ENV PORT=18080

CMD ["./build/StudentManagementSystem"]