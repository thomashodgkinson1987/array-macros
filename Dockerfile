FROM docker.io/library/fedora:42 AS base

LABEL author="Thomas Hodgkinson"
LABEL description="array-macros Build Environment"

USER root

RUN groupadd -g 1000 vscode && \
    useradd -u 1000 -g 1000 -m -s /bin/bash vscode

RUN usermod -aG wheel vscode && \
    echo '%wheel ALL=(ALL) NOPASSWD: ALL' >> /etc/sudoers

RUN --mount=type=cache,target=/var/cache/dnf \
    dnf update -y && \
    dnf install -y \
    git \
    gcc \
    gdb \
    cmake && \
    dnf clean all

WORKDIR /workspaces/array-macros

USER vscode
CMD ["/bin/bash"]
