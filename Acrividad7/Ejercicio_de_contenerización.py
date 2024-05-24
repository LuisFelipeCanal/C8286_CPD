# Utilizar una imagen base de Python oficial
FROM python:3.9-slim
# Establecer el directorio de trabajo en el contenedor
WORKDIR /app
# Copiar el script de Python en el contenedor
COPY scraper.py .
# Instalar aiohttp, necesario para el script
RUN pip install aiohttp
# Comando para ejecutar el script cuando el contenedor se inicie
CMD ["python", "scraper.py"]
