FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
ENV RUNNER_ALLOW_RUNASROOT=1

# Install required packages
RUN apt update && apt install -y \
    curl \
    git \
    build-essential \
    cmake \
    ca-certificates \
    libssl-dev \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /actions-runner

# Download GitHub Actions runner
RUN curl -L -o runner.tar.gz \
    https://github.com/actions/runner/releases/download/v2.331.0/actions-runner-linux-x64-2.331.0.tar.gz \
    && tar xzf runner.tar.gz \
    && rm runner.tar.gz

# Install runner dependencies
RUN ./bin/installdependencies.sh

# Copy entrypoint
COPY entrypoint.sh .
RUN chmod +x entrypoint.sh

ENTRYPOINT ["./entrypoint.sh"]