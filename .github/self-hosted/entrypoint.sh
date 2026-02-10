#!/bin/bash
set -e

if [ -z "$GITHUB_REPO" ] || [ -z "$GITHUB_TOKEN" ]; then
  echo "GITHUB_REPO and GITHUB_TOKEN must be set"
  exit 1
fi

# Only configure if not already configured
if [ ! -f "./.runner" ]; then
  echo "Configuring runner..."
  ./config.sh --unattended \
    --url "https://github.com/$GITHUB_REPO" \
    --token "$GITHUB_TOKEN" \
    --replace \
    --name "$(hostname)-runner" \
    --work "_work"
else
  echo "Runner already configured. Skipping configuration."
fi

# Start the runner
exec ./run.sh
