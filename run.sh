set -e  # Termina el script si ocurre un error

BUILD_DIR="build"
EXECUTABLE="./lvlup"

# Crear el directorio de build si no existe
mkdir -p "$BUILD_DIR"

# Ir a build y compilar
cd "$BUILD_DIR"
cmake ..
make

# Ejecutar el programa
echo "Build successful. Launching LvlUp-CLI..."
$EXECUTABLE
