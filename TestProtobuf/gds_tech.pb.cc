// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: gds_tech.proto

#include "gds_tech.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

PROTOBUF_CONSTEXPR Title::Title(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.version_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.description_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct TitleDefaultTypeInternal {
  PROTOBUF_CONSTEXPR TitleDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~TitleDefaultTypeInternal() {}
  union {
    Title _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 TitleDefaultTypeInternal _Title_default_instance_;
PROTOBUF_CONSTEXPR Package::Package(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.flipchip_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PackageDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PackageDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PackageDefaultTypeInternal() {}
  union {
    Package _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PackageDefaultTypeInternal _Package_default_instance_;
PROTOBUF_CONSTEXPR GdsTech::GdsTech(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.title_)*/nullptr
  , /*decltype(_impl_.package_)*/nullptr
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct GdsTechDefaultTypeInternal {
  PROTOBUF_CONSTEXPR GdsTechDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~GdsTechDefaultTypeInternal() {}
  union {
    GdsTech _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 GdsTechDefaultTypeInternal _GdsTech_default_instance_;
static ::_pb::Metadata file_level_metadata_gds_5ftech_2eproto[3];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_gds_5ftech_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_gds_5ftech_2eproto = nullptr;

const uint32_t TableStruct_gds_5ftech_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Title, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Title, _impl_.version_),
  PROTOBUF_FIELD_OFFSET(::Title, _impl_.description_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Package, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Package, _impl_.flipchip_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::GdsTech, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::GdsTech, _impl_.title_),
  PROTOBUF_FIELD_OFFSET(::GdsTech, _impl_.package_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Title)},
  { 8, -1, -1, sizeof(::Package)},
  { 15, -1, -1, sizeof(::GdsTech)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::_Title_default_instance_._instance,
  &::_Package_default_instance_._instance,
  &::_GdsTech_default_instance_._instance,
};

const char descriptor_table_protodef_gds_5ftech_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016gds_tech.proto\"-\n\005Title\022\017\n\007version\030\001 \001"
  "(\t\022\023\n\013description\030\002 \001(\t\"\033\n\007Package\022\020\n\010fl"
  "ipchip\030\001 \001(\t\";\n\007GdsTech\022\025\n\005title\030\001 \001(\0132\006"
  ".Title\022\031\n\007package\030\002 \001(\0132\010.Packageb\006proto"
  "3"
  ;
static ::_pbi::once_flag descriptor_table_gds_5ftech_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_gds_5ftech_2eproto = {
    false, false, 161, descriptor_table_protodef_gds_5ftech_2eproto,
    "gds_tech.proto",
    &descriptor_table_gds_5ftech_2eproto_once, nullptr, 0, 3,
    schemas, file_default_instances, TableStruct_gds_5ftech_2eproto::offsets,
    file_level_metadata_gds_5ftech_2eproto, file_level_enum_descriptors_gds_5ftech_2eproto,
    file_level_service_descriptors_gds_5ftech_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_gds_5ftech_2eproto_getter() {
  return &descriptor_table_gds_5ftech_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_gds_5ftech_2eproto(&descriptor_table_gds_5ftech_2eproto);

// ===================================================================

class Title::_Internal {
 public:
};

Title::Title(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Title)
}
Title::Title(const Title& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Title* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.version_){}
    , decltype(_impl_.description_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.version_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.version_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_version().empty()) {
    _this->_impl_.version_.Set(from._internal_version(), 
      _this->GetArenaForAllocation());
  }
  _impl_.description_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.description_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_description().empty()) {
    _this->_impl_.description_.Set(from._internal_description(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:Title)
}

inline void Title::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.version_){}
    , decltype(_impl_.description_){}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.version_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.version_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.description_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.description_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

Title::~Title() {
  // @@protoc_insertion_point(destructor:Title)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Title::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.version_.Destroy();
  _impl_.description_.Destroy();
}

void Title::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Title::Clear() {
// @@protoc_insertion_point(message_clear_start:Title)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.version_.ClearToEmpty();
  _impl_.description_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Title::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string version = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_version();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Title.version"));
        } else
          goto handle_unusual;
        continue;
      // string description = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_description();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Title.description"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Title::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Title)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string version = 1;
  if (!this->_internal_version().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_version().data(), static_cast<int>(this->_internal_version().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Title.version");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_version(), target);
  }

  // string description = 2;
  if (!this->_internal_description().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_description().data(), static_cast<int>(this->_internal_description().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Title.description");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_description(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Title)
  return target;
}

size_t Title::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Title)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string version = 1;
  if (!this->_internal_version().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_version());
  }

  // string description = 2;
  if (!this->_internal_description().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_description());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Title::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Title::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Title::GetClassData() const { return &_class_data_; }


void Title::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Title*>(&to_msg);
  auto& from = static_cast<const Title&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Title)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_version().empty()) {
    _this->_internal_set_version(from._internal_version());
  }
  if (!from._internal_description().empty()) {
    _this->_internal_set_description(from._internal_description());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Title::CopyFrom(const Title& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Title)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Title::IsInitialized() const {
  return true;
}

void Title::InternalSwap(Title* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.version_, lhs_arena,
      &other->_impl_.version_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.description_, lhs_arena,
      &other->_impl_.description_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata Title::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_gds_5ftech_2eproto_getter, &descriptor_table_gds_5ftech_2eproto_once,
      file_level_metadata_gds_5ftech_2eproto[0]);
}

// ===================================================================

class Package::_Internal {
 public:
};

Package::Package(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Package)
}
Package::Package(const Package& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Package* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.flipchip_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.flipchip_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.flipchip_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_flipchip().empty()) {
    _this->_impl_.flipchip_.Set(from._internal_flipchip(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:Package)
}

inline void Package::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.flipchip_){}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.flipchip_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.flipchip_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

Package::~Package() {
  // @@protoc_insertion_point(destructor:Package)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Package::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.flipchip_.Destroy();
}

void Package::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Package::Clear() {
// @@protoc_insertion_point(message_clear_start:Package)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.flipchip_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Package::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string flipchip = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_flipchip();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Package.flipchip"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Package::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Package)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string flipchip = 1;
  if (!this->_internal_flipchip().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_flipchip().data(), static_cast<int>(this->_internal_flipchip().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Package.flipchip");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_flipchip(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Package)
  return target;
}

size_t Package::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Package)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string flipchip = 1;
  if (!this->_internal_flipchip().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_flipchip());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Package::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Package::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Package::GetClassData() const { return &_class_data_; }


void Package::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Package*>(&to_msg);
  auto& from = static_cast<const Package&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Package)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_flipchip().empty()) {
    _this->_internal_set_flipchip(from._internal_flipchip());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Package::CopyFrom(const Package& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Package)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Package::IsInitialized() const {
  return true;
}

void Package::InternalSwap(Package* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.flipchip_, lhs_arena,
      &other->_impl_.flipchip_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata Package::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_gds_5ftech_2eproto_getter, &descriptor_table_gds_5ftech_2eproto_once,
      file_level_metadata_gds_5ftech_2eproto[1]);
}

// ===================================================================

class GdsTech::_Internal {
 public:
  static const ::Title& title(const GdsTech* msg);
  static const ::Package& package(const GdsTech* msg);
};

const ::Title&
GdsTech::_Internal::title(const GdsTech* msg) {
  return *msg->_impl_.title_;
}
const ::Package&
GdsTech::_Internal::package(const GdsTech* msg) {
  return *msg->_impl_.package_;
}
GdsTech::GdsTech(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:GdsTech)
}
GdsTech::GdsTech(const GdsTech& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  GdsTech* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.title_){nullptr}
    , decltype(_impl_.package_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_title()) {
    _this->_impl_.title_ = new ::Title(*from._impl_.title_);
  }
  if (from._internal_has_package()) {
    _this->_impl_.package_ = new ::Package(*from._impl_.package_);
  }
  // @@protoc_insertion_point(copy_constructor:GdsTech)
}

inline void GdsTech::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.title_){nullptr}
    , decltype(_impl_.package_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

GdsTech::~GdsTech() {
  // @@protoc_insertion_point(destructor:GdsTech)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void GdsTech::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete _impl_.title_;
  if (this != internal_default_instance()) delete _impl_.package_;
}

void GdsTech::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void GdsTech::Clear() {
// @@protoc_insertion_point(message_clear_start:GdsTech)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && _impl_.title_ != nullptr) {
    delete _impl_.title_;
  }
  _impl_.title_ = nullptr;
  if (GetArenaForAllocation() == nullptr && _impl_.package_ != nullptr) {
    delete _impl_.package_;
  }
  _impl_.package_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GdsTech::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .Title title = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_title(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .Package package = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_package(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* GdsTech::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:GdsTech)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .Title title = 1;
  if (this->_internal_has_title()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::title(this),
        _Internal::title(this).GetCachedSize(), target, stream);
  }

  // .Package package = 2;
  if (this->_internal_has_package()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, _Internal::package(this),
        _Internal::package(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:GdsTech)
  return target;
}

size_t GdsTech::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:GdsTech)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .Title title = 1;
  if (this->_internal_has_title()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.title_);
  }

  // .Package package = 2;
  if (this->_internal_has_package()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.package_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData GdsTech::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    GdsTech::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GdsTech::GetClassData() const { return &_class_data_; }


void GdsTech::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<GdsTech*>(&to_msg);
  auto& from = static_cast<const GdsTech&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:GdsTech)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_title()) {
    _this->_internal_mutable_title()->::Title::MergeFrom(
        from._internal_title());
  }
  if (from._internal_has_package()) {
    _this->_internal_mutable_package()->::Package::MergeFrom(
        from._internal_package());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void GdsTech::CopyFrom(const GdsTech& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:GdsTech)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GdsTech::IsInitialized() const {
  return true;
}

void GdsTech::InternalSwap(GdsTech* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(GdsTech, _impl_.package_)
      + sizeof(GdsTech::_impl_.package_)
      - PROTOBUF_FIELD_OFFSET(GdsTech, _impl_.title_)>(
          reinterpret_cast<char*>(&_impl_.title_),
          reinterpret_cast<char*>(&other->_impl_.title_));
}

::PROTOBUF_NAMESPACE_ID::Metadata GdsTech::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_gds_5ftech_2eproto_getter, &descriptor_table_gds_5ftech_2eproto_once,
      file_level_metadata_gds_5ftech_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Title*
Arena::CreateMaybeMessage< ::Title >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Title >(arena);
}
template<> PROTOBUF_NOINLINE ::Package*
Arena::CreateMaybeMessage< ::Package >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Package >(arena);
}
template<> PROTOBUF_NOINLINE ::GdsTech*
Arena::CreateMaybeMessage< ::GdsTech >(Arena* arena) {
  return Arena::CreateMessageInternal< ::GdsTech >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
