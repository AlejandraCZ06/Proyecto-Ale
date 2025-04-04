// Clase que gestiona un estacionamiento con espacios de distintos tamaños
class ParkingSystem {
    private:
        // Variables que almacenan la cantidad de espacios disponibles para cada tipo de vehículo
        int bigSlots;      // Espacios asignados a autos grandes (tipo 1)
        int mediumSlots;   // Espacios asignados a autos medianos (tipo 2)
        int smallSlots;    // Espacios asignados a autos pequeños (tipo 3)
    
    public:
        // Constructor que inicializa el estacionamiento con la cantidad de espacios disponibles de cada tipo
        ParkingSystem(int big, int medium, int small) {
            bigSlots = big;
            mediumSlots = medium;
            smallSlots = small;
        }
        
        // Método que intenta estacionar un auto según su tipo
        // Retorna true si el auto pudo ser estacionado, false si no hay espacio disponible
        bool addCar(int carType) {
            // Variable que indica si se encontró un espacio para el auto
            bool hayEspacio = false;
            
            // Verifica si hay espacio disponible para un auto grande (tipo 1)
            if (carType == 1) {
                if (bigSlots > 0) { // Si hay al menos un espacio libre
                    bigSlots--; // Se ocupa un espacio
                    hayEspacio = true; // Se confirma que el auto pudo ser estacionado
                }
            }
            
            // Verifica si hay espacio disponible para un auto mediano (tipo 2)
            if (carType == 2) {
                if (mediumSlots > 0) { // Si hay al menos un espacio libre
                    mediumSlots--; // Se ocupa un espacio
                    hayEspacio = true; // Se confirma que el auto pudo ser estacionado
                }
            }
            
            // Verifica si hay espacio disponible para un auto pequeño (tipo 3)
            if (carType == 3) {
                if (smallSlots > 0) { // Si hay al menos un espacio libre
                    smallSlots--; // Se ocupa un espacio
                    hayEspacio = true; // Se confirma que el auto pudo ser estacionado
                }
            }
            
            // Retorna true si el auto pudo ser estacionado, de lo contrario, retorna false
            return hayEspacio;
        }
    };
    