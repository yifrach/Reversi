#ifndef REVERSI_FILEREADER_H
#define REVERSI_FILEREADER_H

class FileReader {
 public:
  FileReader(char* path);
  void readFile(char* ip, int &port);
};

#endif //REVERSI_FILEREADER_H
