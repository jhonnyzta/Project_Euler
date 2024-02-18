public class Mymodule {
    static {
        // Ruta completa a la biblioteca nativa
        String libraryPath = "/home/effez/EulerProject/Id1/withC/Java+C/bin/c/libMymodule.so";

        try {
            // Cargar la biblioteca nativa
            System.load(libraryPath);
        } catch (UnsatisfiedLinkError e) {
            // Manejar cualquier error al cargar la biblioteca
            System.err.println("Error al cargar la biblioteca: " + e.getMessage());
            System.exit(1);
        }
    }

    // Solo la función solve es accesible desde fuera de la clase Mymodule
    public native long solve(long up_bound, long multiple1, long multiple2);

    public static void main(String[] args) {
        Mymodule sumador = new Mymodule();
    }
}