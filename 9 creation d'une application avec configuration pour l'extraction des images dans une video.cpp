#include <iostream>
#include <string>
#include <vector>

// Classe représentant une vidéo
class Video {
private:
    std::string filename;
    int duration; // Durée de la vidéo en secondes

public:
    // Constructeur
    Video(std::string fname, int dur) : filename(fname), duration(dur) {}

    // Méthode pour obtenir la durée de la vidéo
    int getDuration() const {
        return duration;
    }

    // Méthode pour extraire une image à un moment donné dans la vidéo
    void extractImage(int timeInSeconds) const {
        if (timeInSeconds < 0 || timeInSeconds > duration) {
            std::cerr << "Erreur: temps d'extraction invalide (" << timeInSeconds << " secondes).\n";
            return;
        }

        std::cout << "Extraction de l'image de la vidéo '" << filename << "' à " << timeInSeconds << " secondes.\n";
        // Code pour extraire l'image à partir de la vidéo
        // ...
    }
};

// Classe pour l'application d'extraction d'images
class ImageExtractor {
private:
    Video video;

public:
    // Constructeur prenant une vidéo en entrée
    ImageExtractor(const Video& vid) : video(vid) {}

    // Méthode pour extraire des images à des moments spécifiques
    void extractImagesAtTimes(const std::vector<int>& times) const {
        for (int time : times) {
            video.extractImage(time);
        }
    }
};

int main() {
    std::string filename;
    int duration;

    // Demander à l'utilisateur le nom du fichier vidéo et sa durée
    std::cout << "Entrez le nom du fichier vidéo : ";
    std::cin >> filename;
    std::cout << "Entrez la durée de la vidéo (en secondes) : ";
    std::cin >> duration;

    // Création d'une vidéo
    Video myVideo(filename, duration);

    // Création d'un extracteur d'images pour la vidéo
    ImageExtractor extractor(myVideo);

    // Demander à l'utilisateur combien de moments spécifiques il souhaite entrer
    int numTimes;
    std::cout << "Combien de moments spécifiques pour extraire des images ? ";
    std::cin >> numTimes;

    // Lire ces moments spécifiques
    std::vector<int> extractionTimes(numTimes);
    for (int i = 0; i < numTimes; ++i) {
        std::cout << "Entrez le moment d'extraction #" << (i + 1) << " (en secondes) : ";
        std::cin >> extractionTimes[i];
    }

    // Extraction des images à ces moments spécifiques
    extractor.extractImagesAtTimes(extractionTimes);

    return 0;
}
