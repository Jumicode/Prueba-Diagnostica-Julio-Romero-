# Guía Paso a Paso: Instalación de MSYS2 y Compilación de C++ en Windows

## 1. Descargar e Instalar MSYS2

1. **Descargar el instalador:**
   - Ve a la [página oficial de MSYS2](https://www.msys2.org).
   - Haz clic en el enlace de descarga correspondiente al instalador
   - ![1](https://github.com/user-attachments/assets/901b9553-d99b-48b4-8014-df20f17666a5)
   -  ![2](https://github.com/user-attachments/assets/c2c0eaad-e3e0-41b0-9703-9dc4d5ddff09)


2. **Ejecutar el instalador:**
   
  - ![3](https://github.com/user-attachments/assets/4f21e7e9-0d21-4baf-abdb-74e629572032)

   - Sigue las instrucciones del instalador y elige la carpeta de destino .
   - ![4](https://github.com/user-attachments/assets/d5212817-ad28-4d16-80a3-26a35c88f6f9)
   - ![5](https://github.com/user-attachments/assets/04da9f25-0de2-4811-9cbb-7312dda2ce8f)
   - ![6](https://github.com/user-attachments/assets/901bd3f6-a0b1-457f-b29a-ca3d0775723b)
   - ![7](https://github.com/user-attachments/assets/cc1f2ec6-e2ac-438f-9da9-a50bfc7341b2)



## 3. Instalar el Compilador C++ (GCC)

Se utilizará el compilador GCC provisto por `mingw-w64`.

![8](https://github.com/user-attachments/assets/ff8a0060-6d25-44f7-a6e3-a84d0ed7cb03)


## 4. Agregar el Compilador al PATH

Agregar la ruta del compilador al PATH de Windows te permitirá compilar desde cualquier terminal, sin tener que abrir la terminal específica de MSYS2 cada vez.

1. **Ubica la carpeta del compilador:**
   - Si instalaste MSYS2 en `C:\msys64`, la ruta del compilador generalmente es:
     ```
     C:\msys64\mingw64\bin
     ```
   - Confirma que en dicha carpeta se encuentren los ejecutables como `g++.exe` y `gcc.exe`.

2. **Agregar la ruta al PATH:**
   - Abre el **Panel de Control** y ve a **Sistema y seguridad**.
   - Haz clic en **Sistema** y luego en **Configuración avanzada del sistema**.
   - En la ventana **Propiedades del sistema**, haz clic en el botón **Variables de entorno...**.
   - En **Variables del sistema**, selecciona la variable **Path** y haz clic en **Editar...**.
   - Haz clic en **Nuevo** y agrega la ruta:
     ```
     C:\msys64\mingw64\bin
     ```
   - Haz clic en **Aceptar** en todas las ventanas para guardar los cambios.
 - ![9](https://github.com/user-attachments/assets/6a2ca88b-8690-4c6e-bef5-76dfe06a27ed)
 - ![10](https://github.com/user-attachments/assets/976455c2-9205-4ffb-be0a-f7614988943d)
 - ![11](https://github.com/user-attachments/assets/f0842bda-ff43-4111-8ff0-c4c6a39ad9bd)




## 5. Compilar un Programa en C++

A continuación, se describe cómo compilar un programa C++ .

1. **Compilar el programa:**
   - Abre la terminal **MSYS2 MinGW 64-bit** (o una terminal CMD/PowerShell si ya agregaste el compilador al PATH).
   - Navega al directorio donde se encuentra tu archivo y ejecutalo de la siguiente forma :
- ![12](https://github.com/user-attachments/assets/840142c4-3869-4f7c-90f3-24b15a727d18)
- Eso creara un ejecutable de tu archivo cpp.
-![13](https://github.com/user-attachments/assets/0f784186-2869-4c81-914b-f1ffa6560ae2)
- Ahora en tu CMD corre el ejecutable de tu archivo y veras la ejecucion: 

![14](https://github.com/user-attachments/assets/65c1fa5f-ef05-4761-badc-30ede26a1042)


    

## 6. Consejos y Referencias

- **Documentación de MSYS2:**  
  Visita la [página oficial de MSYS2](https://www.msys2.org) para más detalles y documentación.
- **Actualizaciones periódicas:**  
  Actualiza regularmente los paquetes de MSYS2 usando `pacman` para mantener tu entorno actualizado.
- **Ambiente MinGW vs MSYS:**  
  Usa la terminal **MSYS2 MinGW 64-bit** para compilar código C/C++ y la terminal MSYS2 estándar para tareas de administración de paquetes.



