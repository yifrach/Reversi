#ifndef REVERSI_FILEREADER_H
#define REVERSI_FILEREADER_H

class FileReader {
 public:
  FileReader(const char* path);
  const char* readConfigFile(int *port);
 private:
  const char* path;
};

#endif //REVERSI_FILEREADER_H
