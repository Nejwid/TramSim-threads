#!/bin/bash
set -e

# Make sure environment variables are set
if [ -z "$REPO_URL" ] || [ -z "$RUNNER_TOKEN" ]; then
  echo "ERROR: REPO_URL and RUNNER_TOKEN must be set"
  exit 1
fi

# Configure the runner
./config.sh \
  --url "$REPO_URL" \
  --token "$RUNNER_TOKEN" \
  --name "$NAME" \
  --work "_work" \
  --unattended \
  --disableupdate \
  --replace

# Clean up on exit
cleanup() {
  ./config.sh remove --unattended --token "$RUNNER_TOKEN"
}
trap cleanup EXIT

# Run the runner
./run.sh