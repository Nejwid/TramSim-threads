# ===============================
# STAGE 1 – build
# ===============================
FROM gcc:13 AS builder

WORKDIR /app

# CMake + git (FetchContent potrzebuje git)
RUN apt-get update && apt-get install -y \
    cmake \
    git \
    && rm -rf /var/lib/apt/lists/*

# kopiujemy ca³y projekt
COPY . .

# konfiguracja i build
RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    && cmake --build build --target TramSimulatorOOP_main -j$(nproc)

# ===============================
# STAGE 2 – runtime
# ===============================
FROM debian:bookworm-slim

WORKDIR /app

# kopiujemy tylko runtime binary
COPY --from=builder /app/build/TramSimulatorOOP_main /app/TramSimulatorOOP_main

CMD ["./TramSimulatorOOP_main"]
