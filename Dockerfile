FROM gcc:latest

WORKDIR /app

COPY possible.c .

RUN gcc -o possible possible.c

CMD ["./wordhints"]