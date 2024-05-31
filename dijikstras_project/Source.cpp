#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <set>
#include <list>
#include <vector>
#include <climits>

using namespace std;

class ChicRoute {
public:
    vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source)
    {
        unordered_map<int, list<pair<int, int>>> adj; //list of pair
        for (int i = 0; i < edges; i++) 
        {
            int u = vec[i][0]; //n1
            int v = vec[i][1]; //n2
            int w = vec[i][2]; //weight

            adj[u].push_back(make_pair(v, w)); //edge from u to v
            adj[v].push_back(make_pair(u, w)); //edge from v to u
        }

        vector<int> distance(vertices + 1, INT_MAX); //distance arr of length vertices
        set<pair<int, int>> st;
        vector<int> parent(vertices + 1, -1);
        distance[source] = 0;
        st.insert(make_pair(0, source));

        while (!st.empty()) //while my set is not empty
        {
            auto top = *(st.begin());  //fetch top node
            int nodedistance = top.first;
            int topnode = top.second;
            st.erase(st.begin());

            for (auto neighbour : adj[topnode]) //traverse on neighbours now
            {
                if (nodedistance + neighbour.second < distance[neighbour.first])
                {
                    auto record = st.find(make_pair(distance[neighbour.first], neighbour.first)); //find current shortest distance to the neighbor in the set 
                    if (record != st.end())
                    {
                        st.erase(record);  // removes  old record from  set 
                    }
                    distance[neighbour.first] = nodedistance + neighbour.second; //update it with a shorter distance.
                    parent[neighbour.first] = topnode;
                    st.insert(make_pair(distance[neighbour.first], neighbour.first));
                }
            }
        }

        return parent;
    }

    vector<int> getShortestPath(int source, int destination, const vector<int>& parent)
    {
        vector<int> path;
        for (int v = destination; v != -1; v = parent[v])
        {
            path.push_back(v);
            if (v == source) break;
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    vector<vector<int>> edges = {
        {1, 2, 3},
        {1, 3, 5},
        {2, 4, 6},
        {2, 5, 2},
        {3, 4, 4},
        {3, 6, 7},
        {4, 7, 9},
        {5, 7, 8},
        {6, 8, 1},
        {7, 8, 5}
    };

    unordered_map<int, string> shopNames = {
        {1, "Icecream Shop"},
        {2, "Clothes Shop"},
        {3, "Electronics Shop"},
        {4, "Bookstore"},
        {5, "Toy Shop"},
        {6, "Gift Shop"},
        {7, "Game Shop"},
        {8, "Snack Shop"}
    };

    int vertices = 8;
    int edges_count = edges.size();
    int source_shop = -1, destination_shop = -1;

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "ChicRoute", sf::Style::Fullscreen);

    vector<sf::Vector2f> shopPositions = {
        {150, 200}, // Icecream Shop
        {300, 200}, // Clothes Shop
        {450, 100}, // Electronics Shop
        {600, 200}, // Bookstore
        {300, 400}, // Toy Shop
        {750, 100}, // Gift Shop
        {600, 400}, // Game Shop
        {900, 300}  // Snack Shop
    };

    vector<sf::Texture> textures(vertices);
    vector<sf::Sprite> sprites(vertices);

    vector<string> imagePaths = {
        "C:\\Users\\ZASS\\source\\repos\\dijikstras_project\\images\\ice.png",
        "C:\\Users\\ZASS\\source\\repos\\dijikstras_project\\images\\clothesf.png",
        "C:\\Users\\ZASS\\source\\repos\\dijikstras_project\\images\\electric.png",
        "C:\\Users\\ZASS\\source\\repos\\dijikstras_project\\images\\book.png",
        "C:\\Users\\ZASS\\source\\repos\\dijikstras_project\\images\\toy.png",
        "C:\\Users\\ZASS\\source\\repos\\dijikstras_project\\images\\gift.png",
        "C:\\Users\\ZASS\\source\\repos\\dijikstras_project\\images\\game.png",
        "C:\\Users\\ZASS\\source\\repos\\dijikstras_project\\images\\snack.png"
    };

    // Load textures and set sprites
    for (int i = 0; i < vertices; ++i)
    {
        if (!textures[i].loadFromFile(imagePaths[i]))
        {
            cerr << "Error loading image: " << imagePaths[i] << endl;
            return 1;
        }
        sprites[i].setTexture(textures[i]);
    }

    // Desired size for all images
    sf::Vector2f desiredSize(100, 100);

    // Resize images to the same size
    for (int i = 0; i < vertices; ++i)
    {
        sf::FloatRect bounds = sprites[i].getGlobalBounds();
        float scaleX = desiredSize.x / bounds.width;
        float scaleY = desiredSize.y / bounds.height;
        sprites[i].setScale(scaleX, scaleY);
        sprites[i].setPosition(shopPositions[i]);
    }

    sf::RectangleShape sourceButton(sf::Vector2f(300, 50));  // Increase width to 300
    sourceButton.setFillColor(sf::Color(255, 105, 180)); // Pink
    sourceButton.setPosition(10, 500);

    sf::RectangleShape destinationButton(sf::Vector2f(300, 50));  // Increase width to 300
    destinationButton.setFillColor(sf::Color(160, 32, 240)); // Purple
    destinationButton.setPosition(10, 550);

    sf::RectangleShape displayButton(sf::Vector2f(300, 50));  // Increase width to 300
    displayButton.setFillColor(sf::Color(173, 216, 230)); // Light Blue
    displayButton.setPosition(10, 600);  // Position below the graph

    sf::Font font;
    if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
        cerr << "Error loading font" << endl;
        return 1;
    }

    sf::Text sourceButtonText("Select Source", font, 20);
    sourceButtonText.setFillColor(sf::Color::Black);
    sourceButtonText.setPosition(15, 500);

    sf::Text destinationButtonText("Select Destination", font, 20);
    destinationButtonText.setFillColor(sf::Color::Black);
    destinationButtonText.setPosition(15, 550);

    sf::Text displayButtonText("Display Shortest Path", font, 20);
    displayButtonText.setFillColor(sf::Color::Black);
    displayButtonText.setPosition(15, 600);  // Adjust position to match the button

    sf::Text sourceInput("", font, 20);
    sourceInput.setFillColor(sf::Color::Black);
    sourceInput.setPosition(15, 330);

    sf::Text destinationInput("", font, 20);
    destinationInput.setFillColor(sf::Color::Black);
    destinationInput.setPosition(15, 360);

    sf::Text shortestPathDistanceText("", font, 20);
    shortestPathDistanceText.setFillColor(sf::Color::Black);
    shortestPathDistanceText.setPosition(350, 600); // Position in front of the "Display Shortest Path" button

    // Add title and subtitle
    sf::Text titleText("ChicRoute", font, 40);
    titleText.setFillColor(sf::Color::Black);
    titleText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    titleText.setPosition(500, 10);

    sf::Text subtitleText("Your Friendly Pathfinder To Make Your Shopping Less Tiring", font, 25);
    subtitleText.setFillColor(sf::Color::Yellow);
    subtitleText.setStyle(sf::Text::Italic);
    subtitleText.setPosition(400, 60);

    bool selectingSource = false;
    bool selectingDestination = false;
    bool sourceEntered = false;
    bool destinationEntered = false;

    bool displayPath = false;

    ChicRoute chicRoute;
    vector<int> shortestPath;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sourceButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        selectingSource = true;
                        selectingDestination = false;
                    }
                    else if (destinationButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        selectingSource = false;
                        selectingDestination = true;
                    }
                    else if (displayButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        if (sourceEntered && destinationEntered) {
                            shortestPath = chicRoute.getShortestPath(source_shop, destination_shop, chicRoute.dijkstra(edges, vertices, edges_count, source_shop));
                            displayPath = true;

                            // Calculate and display shortest path distance
                            int distance = 0;
                            for (size_t i = 0; i < shortestPath.size() - 1; ++i) {
                                for (const auto& edge : edges) {
                                    if ((edge[0] == shortestPath[i] && edge[1] == shortestPath[i + 1]) ||
                                        (edge[1] == shortestPath[i] && edge[0] == shortestPath[i + 1])) {
                                        distance += edge[2];
                                        break;
                                    }
                                }
                            }
                            shortestPathDistanceText.setString("Shortest Distance: " + to_string(distance));
                        }
                    }
                    else {
                        for (int i = 0; i < vertices; ++i) {
                            if (sprites[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (selectingSource) {
                                    source_shop = i + 1;
                                    sourceEntered = true;
                                    selectingSource = false;
                                    // Update source button text with shop name
                                    sourceButtonText.setString("Source: " + shopNames[source_shop]);
                                }
                                else if (selectingDestination) {
                                    destination_shop = i + 1;
                                    destinationEntered = true;
                                    selectingDestination = false;
                                    // Update destination button text with shop name
                                    destinationButtonText.setString("Destination: " + shopNames[destination_shop]);
                                }
                            }
                        }
                    }
                }
            }
        }

        window.clear(sf::Color(255, 255, 224)); // Very light yellow

        // Calculate corners of sprites
        vector<vector<sf::Vector2f>> spriteCorners(vertices);
        for (int i = 0; i < vertices; ++i) {
            sf::FloatRect bounds = sprites[i].getGlobalBounds();
            sf::Vector2f position = sprites[i].getPosition();
            spriteCorners[i] = {
                {position.x, position.y}, // top-left
                {position.x + bounds.width, position.y}, // top-right
                {position.x, position.y + bounds.height}, // bottom-left
                {position.x + bounds.width, position.y + bounds.height} // bottom-right
            };
        }

        // Draw edges and label their weights
        for (auto& edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            int weight = edge[2];

            // Find the closest corners
            sf::Vector2f closestU, closestV;
            float minDistance = FLT_MAX;
            for (auto& cornerU : spriteCorners[u]) {
                for (auto& cornerV : spriteCorners[v]) {
                    float distance = hypot(cornerU.x - cornerV.x, cornerU.y - cornerV.y);
                    if (distance < minDistance) {
                        minDistance = distance;
                        closestU = cornerU;
                        closestV = cornerV;
                    }
                }
            }

            sf::Vertex line[] = {
                sf::Vertex(closestU, sf::Color::Black),
                sf::Vertex(closestV, sf::Color::Black)
            };
            window.draw(line, 2, sf::Lines);

            // Calculate mid-point for weight label
            sf::Vector2f midPoint = (closestU + closestV) / 2.0f;
            sf::Text weightLabel(to_string(weight), font, 15);
            weightLabel.setFillColor(sf::Color::Black);
            weightLabel.setPosition(midPoint);
            window.draw(weightLabel);
        }

        // Draw shops as sprites
        for (int i = 0; i < sprites.size(); ++i) {
            if (i + 1 == source_shop) {
                sprites[i].setColor(sf::Color::Green);
            }
            else if (i + 1 == destination_shop) {
                sprites[i].setColor(sf::Color::Red);
            }
            else {
                sprites[i].setColor(sf::Color::White);
            }
            window.draw(sprites[i]);
        }

        // Draw buttons
        window.draw(sourceButton);
        window.draw(destinationButton);
        window.draw(displayButton);
        window.draw(sourceButtonText);
        window.draw(destinationButtonText);
        window.draw(displayButtonText);

        // Draw input text
        window.draw(sourceInput);
        window.draw(destinationInput);

        // Draw shortest path distance text
        window.draw(shortestPathDistanceText);

        // Display shortest path if requested
        if (displayPath) {
            for (size_t i = 0; i < shortestPath.size() - 1; ++i) {
                int u = shortestPath[i] - 1;
                int v = shortestPath[i + 1] - 1;

                // Find the closest corners
                sf::Vector2f closestU, closestV;
                float minDistance = FLT_MAX;
                for (auto& cornerU : spriteCorners[u]) {
                    for (auto& cornerV : spriteCorners[v]) {
                        float distance = hypot(cornerU.x - cornerV.x, cornerU.y - cornerV.y);
                        if (distance < minDistance) {
                            minDistance = distance;
                            closestU = cornerU;
                            closestV = cornerV;
                        }
                    }
                }

                sf::Vertex line[] = {
                    sf::Vertex(closestU, sf::Color::Magenta),
                    sf::Vertex(closestV, sf::Color::Magenta)
                };
                window.draw(line, 2, sf::Lines);
            }
            displayPath = false; // Reset display flag
        }

        // Draw title and subtitle
        window.draw(titleText);
        window.draw(subtitleText);

        window.display();
    }

    return 0;
}
