FROM python:3.7.5-stretch

ENV APP_DIR /usr/src/app

RUN	apt-get update && \
    apt-get install -y nano && \
    pip3 install --upgrade pip && \
    pip3 install pytest-runner && \
    mkdir -p ${APP_DIR}/web && \
    mkdir -p ${APP_DIR}/conf && \
    mkdir -p ${APP_DIR}/logs && \
    rm -rf /var/cache/apk/*

COPY . ${APP_DIR}
WORKDIR ${APP_DIR}

EXPOSE 5011

RUN pip3 install -r requirements.txt

ENTRYPOINT gunicorn --workers 4 --timeout 300 --bind 0.0.0.0:5011 server:app