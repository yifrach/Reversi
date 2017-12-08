#ifndef SERVER_FILEREADER_H
#define SERVER_FILEREADER_H

class FileReader {
 public:
  FileReader();
  int readConfigFile(const char* path); // Returns the servers port number
 private:
  const char* path;
};

#endif //SERVER_FILEREADER_H
