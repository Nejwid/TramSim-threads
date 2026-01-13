# ===============================
# STAGE 1 – build
# ===============================
FROM gcc:13 AS builder

WORKDIR /app

# narzêdzia wymagane do CMake + FetchContent + build
RUN apt-get update && apt-get install -y \
    cmake \
    git \
    build-essential \
    ca-certificates \
    curl \
    && rm -rf /var/lib/apt/lists/*

# kopiujemy projekt CMake
COPY app/ .

# build z statycznym linkowaniem libstdc++ i libgcc
RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-static-libstdc++ -static-libgcc" \
    && cmake --build build --target TramSimulatorOOP_main -j$(nproc)

# ===============================
# STAGE 2 – runtime (minimalny)
# ===============================
FROM debian:bookworm-slim

WORKDIR /app

# potrzebne tylko dla curl w system()
RUN apt-get update && apt-get install -y \
    curl \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

# tworzymy katalog output w runtime
RUN mkdir -p /app/output

# kopiujemy gotow¹, statycznie zlinkowan¹ binarkê
COPY --from=builder /app/build/TramSimulatorOOP_main .

# uruchomienie programu
CMD ["./TramSimulatorOOP_main"]
