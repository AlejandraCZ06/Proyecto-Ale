#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Twitter {
public:
    int timeStamp;  // Variable para llevar el contador de tiempo (timestamp) de los tweets
    unordered_map<int, vector<pair<int, int>>> tweets; // Mapa para almacenar los tweets (usuario -> lista de tweets)
    unordered_map<int, unordered_set<int>> follows; // Mapa para almacenar los usuarios que sigue cada usuario (usuario -> conjunto de seguidores)

    // Constructor de la clase Twitter
    Twitter() {
        timeStamp = 0; // Inicializa el timestamp en 0
    }

    // Función para publicar un tweet
    void postTweet(int userId, int tweetId) {
        // Guarda el tweet junto con su timestamp (tiempo)
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    // Función para obtener el feed de noticias de un usuario
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> feed; // Cola de prioridad para almacenar los tweets (más reciente primero)
        
        // Agregar los tweets del propio usuario
        for (auto& t : tweets[userId]) {
            feed.push(t);
        }

        // Agregar los tweets de los usuarios a los que sigue el usuario
        for (auto& followeeId : follows[userId]) {
            for (auto& t : tweets[followeeId]) {
                feed.push(t);
            }
        }

        // Obtener los 10 tweets más recientes (si existen)
        vector<int> result;
        int count = 0;
        while (!feed.empty() && count < 10) {
            result.push_back(feed.top().second); // Agregar el ID del tweet al resultado
            feed.pop(); // Eliminar el tweet más antiguo (de acuerdo con el orden de la cola)
            count++;
        }

        return result; // Devolver los 10 tweets más recientes
    }

    // Función para hacer que un usuario siga a otro
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // Un usuario no puede seguirse a sí mismo
        follows[followerId].insert(followeeId); // El usuario sigue a otro
    }

    // Función para hacer que un usuario deje de seguir a otro
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId); // Eliminar al usuario del conjunto de seguidores
    }
};

int main() {
    // Crear un objeto de Twitter
    Twitter* twitter = new Twitter();
    
    // Definir las operaciones y su entrada
    vector<string> operations = {"Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"};
    vector<vector<int>> inputs = { {}, {1, 5}, {1}, {1, 2}, {2, 6}, {1}, {1, 2}, {1} };
    
    // Resultado para almacenar las salidas de las operaciones
    vector<vector<int>> result;
    
    // Iterar sobre las operaciones
    for (int i = 0; i < operations.size(); ++i) {
        if (operations[i] == "Twitter") {
            // Crear un nuevo objeto Twitter
            twitter = new Twitter();
            result.push_back({}); // No hay salida para esta operación, se agrega un vector vacío
        } else if (operations[i] == "postTweet") {
            // Publicar un tweet con el ID y el tweet proporcionados
            twitter->postTweet(inputs[i][0], inputs[i][1]);
            result.push_back({}); // No hay salida para esta operación, se agrega un vector vacío
        } else if (operations[i] == "getNewsFeed") {
            // Obtener el feed de noticias de un usuario
            result.push_back(twitter->getNewsFeed(inputs[i][0])); // Agregar el resultado del feed
        } else if (operations[i] == "follow") {
            // Hacer que un usuario siga a otro
            twitter->follow(inputs[i][0], inputs[i][1]);
            result.push_back({}); // No hay salida para esta operación, se agrega un vector vacío
        } else if (operations[i] == "unfollow") {
            // Hacer que un usuario deje de seguir a otro
            twitter->unfollow(inputs[i][0], inputs[i][1]);
            result.push_back({}); // No hay salida para esta operación, se agrega un vector vacío
        }
    }
    
    // Imprimir los resultados en el formato esperado
    for (auto& res : result) {
        if (res.empty()) {
            cout << "null"; // Si el resultado está vacío, imprimimos "null"
        } else {
            cout << "[";
            for (int i = 0; i < res.size(); ++i) {
                cout << res[i]; // Imprimir cada ID de tweet
                if (i < res.size() - 1) cout << ","; // Agregar una coma si no es el último elemento
            }
            cout << "]";
        }
        cout << endl; // Salto de línea después de cada resultado
    }

    return 0; // Fin del programa
}