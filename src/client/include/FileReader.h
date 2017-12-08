#ifndef REVERSI_FILEREADER_H
#define REVERSI_FILEREADER_H

class FileReader {
 public:
  FileReader(char* path);
  char* readConfigFile();
 private:
  char* path;
};

#endif //REVERSI_FILEREADER_H
