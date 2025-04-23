#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Twitter {
public:
    int timeStamp;
    unordered_map<int, vector<pair<int, int>>> tweets; // Mapa de usuario -> tweet (con timestamp)
    unordered_map<int, unordered_set<int>> follows; // Mapa de seguidores (usuario -> usuarios que sigue)

    // Constructor que inicializa el contador de timestamps
    Twitter() {
        timeStamp = 0;
    }

    // Publica un tweet con un ID dado
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    // Obtiene el feed de noticias de un usuario
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> feed; // Cola de prioridad para ordenar los tweets por timestamp (más reciente primero)
        
        // Agregar los tweets del propio usuario
        for (auto& t : tweets[userId]) {
            feed.push(t);
        }

        // Agregar los tweets de los usuarios que sigue
        for (auto& followeeId : follows[userId]) {
            for (auto& t : tweets[followeeId]) {
                feed.push(t);
            }
        }

        // Recuperar los 10 tweets más recientes
        vector<int> result;
        int count = 0;
        while (!feed.empty() && count < 10) {
            result.push_back(feed.top().second); // Agregar el tweet ID al resultado
            feed.pop();
            count++;
        }

        return result;
    }

    // Hace que un usuario siga a otro
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // Un usuario no puede seguirse a sí mismo
        follows[followerId].insert(followeeId);
    }

    // Hace que un usuario deje de seguir a otro
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

int main() {
    // Crear un objeto Twitter
    Twitter* twitter = new Twitter();
    
    // Definir las operaciones y su entrada
    vector<string> operations = {"Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"};
    vector<vector<int>> inputs = { {}, {1, 5}, {1}, {1, 2}, {2, 6}, {1}, {1, 2}, {1} };
    
    // Resultado a devolver
    vector<vector<int>> result;
    
    for (int i = 0; i < operations.size(); ++i) {
        if (operations[i] == "Twitter") {
            twitter = new Twitter();
            result.push_back({});
        } else if (operations[i] == "postTweet") {
            twitter->postTweet(inputs[i][0], inputs[i][1]);
            result.push_back({});
        } else if (operations[i] == "getNewsFeed") {
            result.push_back(twitter->getNewsFeed(inputs[i][0]));
        } else if (operations[i] == "follow") {
            twitter->follow(inputs[i][0], inputs[i][1]);
            result.push_back({});
        } else if (operations[i] == "unfollow") {
            twitter->unfollow(inputs[i][0], inputs[i][1]);
            result.push_back({});
        }
    }
    
    // Imprimir los resultados en el formato esperado
    for (auto& res : result) {
        if (res.empty()) {
            cout << "null";
        } else {
            cout << "[";
            for (int i = 0; i < res.size(); ++i) {
                cout << res[i];
                if (i < res.size() - 1) cout << ",";
            }
            cout << "]";
        }
        cout << endl;
    }

    return 0;
}