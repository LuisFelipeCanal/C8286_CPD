
# Desarrollo Evaluacion 1!

 **Listar todos los procesos con detalles completos**
 ![image.png])

**Buscar procesos específicos por nombre:**

![image.png]()


**Mostrar procesos en un árbol jerárquico (útil para ver relaciones padre-hijo enprocesos concurrentes):**

[![image.png]()


**Mostrar procesos de un usuario específico:**

![image.png]()


**Escribe un script para verificar y reiniciar automáticamente un proceso si no está corriendo.**


![image.png]()
![image.png]()



## EJERCICIOS GREP

**Filtrar  errores  específicos en  logs de  aplicaciones  paralelas**:

![image.png]()

**Monitorizar la creación de procesos no autorizados** :

![image.png]()

![image.png]()


**Contar el  número de  ocurriencias de  condiciones de  carrera  registradas** :

![image.png]()


**Extraer IPs que han accedido  concurrentemente a un recursos**:

![image.png]()


**Automatizar la alerta de sobrecarga en un servicio distribuida**

![image.png]()


**Monitorear errores de conexión en aplicaciones concurrentes** :

![image.png]()


**Validar la correcta sincronización en operaciones distribuidas**

**Monitorizar la creación de procesos no autorizados**

**Detectar y alertar sobre ataques de fuerza bruta SSH**

![image.png]()



## EJERCICIOS PIPES

`watch "ps aux | grep '[a]pache2' | awk '{print \$1, \$2, \$3, \$4, \$11}"`


![image.png]()

`cat /var/log/myapp.log | grep "ERROR" | awk '{print $NF}' | sort | uniq -c | sort -nr`


![image.png]()

`systemctl --failed | grep "loaded units listed" || systemctl restart $(awk '{print $1}')`


![image.png]()


`ps -eo pid,ppid,%cpu,cmd --sort=-%cpu | awk '$3 > 80 {print "Alto uso de CPU: ", $1}' | mail -s "Alerta CPU" [admin@example.com`](mailto:admin@example.com)


![image.png]()

`ls /var/log/*.log | xargs -n 1 -P 5 -I {} ssh nodo_remoto "grep 'ERROR' {} > errores_{}.txt"`


![image.png]()


`echo "8.8.8.8 www.example.com" | xargs -n 1 ping -c 1 | grep "bytes from" || echo "$(date)Fallo de ping" >> fallos_ping.txt`


![image.png]()


`ps -eo user,%cpu,%mem,cmd | awk '/httpd/ {cpu+=$2; mem+=$3; count++} END {print"Apache - CPU:", cpu/count, "Mem:", mem/count}'`


![image.png]()



## EJERCICIOS BASH


1.  **Script de Monitoreo de Procesos:**
-   Define una función para convertir el uso de memoria de KB a MB.
-   Define una función para verificar el uso de recursos de los procesos y tomar acciones si se exceden los umbrales.
-   En un bucle infinito, llama a la función **verificar_procesos()** para monitorear continuamente los procesos.

2.  **Script de Backup de Directorios:**

-   Define una lista de directorios a respaldar y el destino del respaldo.
-   Define una función **backup_dir()** para respaldar cada directorio en un archivo tar.gz con marca de tiempo.
-   Exporta la función **backup_dir** y la variable **DESTINO_BACKUP**.
-   Utiliza el comando **parallel** para ejecutar **backup_dir()** en paralelo para cada directorio en la lista.

3.  **Script de Distribución de Tareas:**

-   Define una lista de nodos y una lista de nombres de archivos de tareas.
-   Define una función **distribuir_tareas()** para distribuir las tareas entre los nodos utilizando SSH y SCP.
-   Itera sobre las tareas y los nodos, copiando cada tarea al nodo correspondiente y ejecutándola en segundo plano.
-   Espera a que todas las tareas terminen antes de salir.

4.  **Script de Bloqueo y Liberación de Recurso Compartido:**

-   Define la ubicación del archivo de bloqueo y la ubicación del recurso compartido.
-   Define funciones para adquirir y liberar el bloqueo del recurso.
-   Utiliza un bucle para intentar adquirir el bloqueo y espera si no puede adquirirlo inmediatamente.
-   Accede al recurso compartido y simula un trabajo.
-   Libera el bloqueo después de terminar de trabajar con el recurso.

5.  **Script de Recolección de Métricas de Nodos:**

-   Define una lista de nodos y un archivo para almacenar las métricas.
-   Define una función **recolectar_metricas()** para recopilar métricas de CPU, memoria y disco de cada nodo utilizando SSH.
-   Itera sobre los nodos, ejecuta comandos remotos para obtener las métricas y las guarda en el archivo especificad

## EJERCICIOS AWK


El comando ps aux muestra información sobre los procesos del sistema, y awk '{print $1, $2, $3, $4, $11}' se encarga de filtrar y mostrar solo ciertos campos de esa información, incluyendo el usuario, el PID, el %CPU, el %MEM y el nombre del comando de los primeros 10 procesos.

![image.png]()


1.  El primer script **tail -f /var/log/app.log | grep "ERROR" | awk '{print $1, $2, $NF}'** muestra en tiempo real las líneas del archivo **/var/log/app.log** que contienen la palabra "ERROR", y luego imprime el primer y segundo campo de esas líneas junto con el último campo.
2.  El resultado de aplicar este script depende del contenido del archivo **/var/log/app.log**. Si hay líneas que contienen la palabra "ERROR", entonces esas líneas junto con sus campos se mostrarán en la salida.
3.  El segundo script **ps -eo user,pid,pcpu,pmem,cmd | grep apache2 | awk '$3 > 50.0 || $4 > 50.0 {print "Alto recurso: ", $0}'** muestra información sobre los procesos relacionados con "apache2" cuyo uso de CPU (**pcpu**) o uso de memoria (**pmem**) sea mayor al 50%. Si encuentra alguno, imprime un mensaje indicando "Alto recurso" seguido de toda la línea de información del proceso.

![image.png]()



## EJERCICIOS

`ps  -eo pid,pcpu,pmem,cmd | awk '$2 > 10.0 || $3 > 10.0'`


![image.png]()


`awk '{print $0 >> ("output-" $4 ".log")}'  /var/log/syslog`


![image.png]()


`grep "Failed password" /var/log/auth.log | awk '{print $(NF-3)}' | sort | uniq  -c | sort  -nr`


![image.png]()


`find .  -type f  -name "*.py"  -exec ls  -l {} + | awk '{sum += $5} END {print "Espacio totalusado por archivos .py: ", sum}'`


![image.png]()


`ps  -eo state | awk '/D/ {d++} /R/ {r++} END {print "Espera (D):", d, "-  Ejecución (R):",r}`


![image.png]()



`awk '/SwapTotal/ {total=$2} /SwapFree/ {free=$2} END {if ((total-free)/total*100 >20.0) print "Alerta: Uso excesivo de swap"}' /proc/meminfo`


![image.png]()



`s  -l | awk '!/^total/ && !/^d/ {sum += $5} END {print "Uso total de disco (sinsubdirectorios):", sum}`


![image.png]()
