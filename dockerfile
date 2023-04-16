FROM ubuntu

RUN apt-get update && apt -y install build-essential

COPY pr3.cpp .

RUN g++ pr3.cpp -o pr3

CMD ./pr3

