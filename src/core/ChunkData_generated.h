// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CHUNKDATA_TBSD_H_
#define FLATBUFFERS_GENERATED_CHUNKDATA_TBSD_H_

#include "flatbuffers/flatbuffers.h"

#include "Tile_generated.h"

namespace tbsd {

struct TileArray;
struct TileArrayBuilder;
struct TileArrayT;

struct ChunkData;
struct ChunkDataBuilder;
struct ChunkDataT;

struct TileArrayT : public flatbuffers::NativeTable {
  typedef TileArray TableType;
  std::vector<tbsd::Tile> y{};
};

struct TileArray FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef TileArrayT NativeTableType;
  typedef TileArrayBuilder Builder;
  struct Traits;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_Y = 4
  };
  const flatbuffers::Vector<const tbsd::Tile *> *y() const {
    return GetPointer<const flatbuffers::Vector<const tbsd::Tile *> *>(VT_Y);
  }
  flatbuffers::Vector<const tbsd::Tile *> *mutable_y() {
    return GetPointer<flatbuffers::Vector<const tbsd::Tile *> *>(VT_Y);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_Y) &&
           verifier.VerifyVector(y()) &&
           verifier.EndTable();
  }
  TileArrayT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(TileArrayT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<TileArray> Pack(flatbuffers::FlatBufferBuilder &_fbb, const TileArrayT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct TileArrayBuilder {
  typedef TileArray Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_y(flatbuffers::Offset<flatbuffers::Vector<const tbsd::Tile *>> y) {
    fbb_.AddOffset(TileArray::VT_Y, y);
  }
  explicit TileArrayBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<TileArray> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<TileArray>(end);
    return o;
  }
};

inline flatbuffers::Offset<TileArray> CreateTileArray(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<const tbsd::Tile *>> y = 0) {
  TileArrayBuilder builder_(_fbb);
  builder_.add_y(y);
  return builder_.Finish();
}

struct TileArray::Traits {
  using type = TileArray;
  static auto constexpr Create = CreateTileArray;
};

inline flatbuffers::Offset<TileArray> CreateTileArrayDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<tbsd::Tile> *y = nullptr) {
  auto y__ = y ? _fbb.CreateVectorOfStructs<tbsd::Tile>(*y) : 0;
  return tbsd::CreateTileArray(
      _fbb,
      y__);
}

flatbuffers::Offset<TileArray> CreateTileArray(flatbuffers::FlatBufferBuilder &_fbb, const TileArrayT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct ChunkDataT : public flatbuffers::NativeTable {
  typedef ChunkData TableType;
  uint64_t id = 0;
  std::vector<std::unique_ptr<tbsd::TileArrayT>> x{};
};

struct ChunkData FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ChunkDataT NativeTableType;
  typedef ChunkDataBuilder Builder;
  struct Traits;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4,
    VT_X = 6
  };
  uint64_t id() const {
    return GetField<uint64_t>(VT_ID, 0);
  }
  bool mutate_id(uint64_t _id) {
    return SetField<uint64_t>(VT_ID, _id, 0);
  }
  const flatbuffers::Vector<flatbuffers::Offset<tbsd::TileArray>> *x() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<tbsd::TileArray>> *>(VT_X);
  }
  flatbuffers::Vector<flatbuffers::Offset<tbsd::TileArray>> *mutable_x() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<tbsd::TileArray>> *>(VT_X);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint64_t>(verifier, VT_ID) &&
           VerifyOffset(verifier, VT_X) &&
           verifier.VerifyVector(x()) &&
           verifier.VerifyVectorOfTables(x()) &&
           verifier.EndTable();
  }
  ChunkDataT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(ChunkDataT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<ChunkData> Pack(flatbuffers::FlatBufferBuilder &_fbb, const ChunkDataT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct ChunkDataBuilder {
  typedef ChunkData Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(uint64_t id) {
    fbb_.AddElement<uint64_t>(ChunkData::VT_ID, id, 0);
  }
  void add_x(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<tbsd::TileArray>>> x) {
    fbb_.AddOffset(ChunkData::VT_X, x);
  }
  explicit ChunkDataBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<ChunkData> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ChunkData>(end);
    return o;
  }
};

inline flatbuffers::Offset<ChunkData> CreateChunkData(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t id = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<tbsd::TileArray>>> x = 0) {
  ChunkDataBuilder builder_(_fbb);
  builder_.add_id(id);
  builder_.add_x(x);
  return builder_.Finish();
}

struct ChunkData::Traits {
  using type = ChunkData;
  static auto constexpr Create = CreateChunkData;
};

inline flatbuffers::Offset<ChunkData> CreateChunkDataDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t id = 0,
    const std::vector<flatbuffers::Offset<tbsd::TileArray>> *x = nullptr) {
  auto x__ = x ? _fbb.CreateVector<flatbuffers::Offset<tbsd::TileArray>>(*x) : 0;
  return tbsd::CreateChunkData(
      _fbb,
      id,
      x__);
}

flatbuffers::Offset<ChunkData> CreateChunkData(flatbuffers::FlatBufferBuilder &_fbb, const ChunkDataT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline TileArrayT *TileArray::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::make_unique<TileArrayT>();
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void TileArray::UnPackTo(TileArrayT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = y(); if (_e) { _o->y.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->y[_i] = *_e->Get(_i); } } }
}

inline flatbuffers::Offset<TileArray> TileArray::Pack(flatbuffers::FlatBufferBuilder &_fbb, const TileArrayT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateTileArray(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<TileArray> CreateTileArray(flatbuffers::FlatBufferBuilder &_fbb, const TileArrayT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const TileArrayT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _y = _o->y.size() ? _fbb.CreateVectorOfStructs(_o->y) : 0;
  return tbsd::CreateTileArray(
      _fbb,
      _y);
}

inline ChunkDataT *ChunkData::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::make_unique<ChunkDataT>();
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void ChunkData::UnPackTo(ChunkDataT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = id(); _o->id = _e; }
  { auto _e = x(); if (_e) { _o->x.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->x[_i] = std::unique_ptr<tbsd::TileArrayT>(_e->Get(_i)->UnPack(_resolver)); } } }
}

inline flatbuffers::Offset<ChunkData> ChunkData::Pack(flatbuffers::FlatBufferBuilder &_fbb, const ChunkDataT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateChunkData(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<ChunkData> CreateChunkData(flatbuffers::FlatBufferBuilder &_fbb, const ChunkDataT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const ChunkDataT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _id = _o->id;
  auto _x = _o->x.size() ? _fbb.CreateVector<flatbuffers::Offset<tbsd::TileArray>> (_o->x.size(), [](size_t i, _VectorArgs *__va) { return CreateTileArray(*__va->__fbb, __va->__o->x[i].get(), __va->__rehasher); }, &_va ) : 0;
  return tbsd::CreateChunkData(
      _fbb,
      _id,
      _x);
}

inline const tbsd::ChunkData *GetChunkData(const void *buf) {
  return flatbuffers::GetRoot<tbsd::ChunkData>(buf);
}

inline const tbsd::ChunkData *GetSizePrefixedChunkData(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<tbsd::ChunkData>(buf);
}

inline ChunkData *GetMutableChunkData(void *buf) {
  return flatbuffers::GetMutableRoot<ChunkData>(buf);
}

inline bool VerifyChunkDataBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<tbsd::ChunkData>(nullptr);
}

inline bool VerifySizePrefixedChunkDataBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<tbsd::ChunkData>(nullptr);
}

inline void FinishChunkDataBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<tbsd::ChunkData> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedChunkDataBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<tbsd::ChunkData> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<tbsd::ChunkDataT> UnPackChunkData(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<tbsd::ChunkDataT>(GetChunkData(buf)->UnPack(res));
}

inline std::unique_ptr<tbsd::ChunkDataT> UnPackSizePrefixedChunkData(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<tbsd::ChunkDataT>(GetSizePrefixedChunkData(buf)->UnPack(res));
}

}  // namespace tbsd

#endif  // FLATBUFFERS_GENERATED_CHUNKDATA_TBSD_H_
