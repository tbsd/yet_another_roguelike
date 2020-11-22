#include "Chunk.h"
#include <sstream>

namespace tbsd {
  unsigned long long Chunk::nextId = 0;

  std::string Chunk::toString() const {
    std::string result;
    result.reserve(chunkXSize * chunkYSize * 2 + chunkYSize);
    for (Coordinate y = 0; y < chunkYSize; ++y) {
      for (Coordinate x = 0; x < chunkXSize; ++x) {
        //TODO: replace with sensible casting to char. std::stringstream?
        result.push_back(std::to_string(static_cast<int>(at(x, y)->type())).c_str()[0]);
        result.push_back(' ');
      }
      result.push_back('\n');
    }
    return result;
  }

  void Chunk::store() {
    if (isLoaded()) {
      flatbuffers::FlatBufferBuilder fbb;
      fbb.Finish(ChunkData::Pack(fbb, &data));
      try {
        IO::writeToFile(IO::getChunkPath(id), fbb.GetBufferPointer(), fbb.GetSize());
        data.x.clear();
      } catch (std::runtime_error &ex) {
        Log::send(ex.what(), Log::Type::Error);
      }
    }
  }

  void Chunk::load() {
    if (!isLoaded()) {
      auto raw = IO::readFromFile(IO::getChunkPath(id));
      if (raw) {
        GetChunkData(raw.get())->UnPackTo(&data);
      } else {
        data.x.reserve(chunkXSize);
        for (size_t x = 0; x < chunkXSize; ++x) {
          data.x.push_back(std::make_unique<TileArrayT>());
          data.x[x]->y.reserve(chunkYSize);
          for (size_t y = 0; y < chunkYSize; ++y)
            data.x[x]->y.emplace_back();
        }
      }
    }
  }
}