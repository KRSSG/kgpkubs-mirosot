// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: command-packet.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "command-packet.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* StrategyPacket_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  StrategyPacket_reflection_ = NULL;
const ::google::protobuf::Descriptor* StrategyPacket_Tactic_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  StrategyPacket_Tactic_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* StrategyPacket_Play_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* StrategyPacket_TacticID_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* StrategyPacket_Which_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_command_2dpacket_2eproto() {
  protobuf_AddDesc_command_2dpacket_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "command-packet.proto");
  GOOGLE_CHECK(file != NULL);
  StrategyPacket_descriptor_ = file->message_type(0);
  static const int StrategyPacket_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StrategyPacket, play_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StrategyPacket, tactic_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StrategyPacket, which_),
  };
  StrategyPacket_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      StrategyPacket_descriptor_,
      StrategyPacket::default_instance_,
      StrategyPacket_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StrategyPacket, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StrategyPacket, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(StrategyPacket));
  StrategyPacket_Tactic_descriptor_ = StrategyPacket_descriptor_->nested_type(0);
  static const int StrategyPacket_Tactic_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StrategyPacket_Tactic, tid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StrategyPacket_Tactic, botid_),
  };
  StrategyPacket_Tactic_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      StrategyPacket_Tactic_descriptor_,
      StrategyPacket_Tactic::default_instance_,
      StrategyPacket_Tactic_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StrategyPacket_Tactic, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StrategyPacket_Tactic, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(StrategyPacket_Tactic));
  StrategyPacket_Play_descriptor_ = StrategyPacket_descriptor_->enum_type(0);
  StrategyPacket_TacticID_descriptor_ = StrategyPacket_descriptor_->enum_type(1);
  StrategyPacket_Which_descriptor_ = StrategyPacket_descriptor_->enum_type(2);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_command_2dpacket_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    StrategyPacket_descriptor_, &StrategyPacket::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    StrategyPacket_Tactic_descriptor_, &StrategyPacket_Tactic::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_command_2dpacket_2eproto() {
  delete StrategyPacket::default_instance_;
  delete StrategyPacket_reflection_;
  delete StrategyPacket_Tactic::default_instance_;
  delete StrategyPacket_Tactic_reflection_;
}

void protobuf_AddDesc_command_2dpacket_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\024command-packet.proto\"\217\006\n\016StrategyPacke"
    "t\022\"\n\004play\030\001 \001(\0162\024.StrategyPacket.Play\022&\n"
    "\006tactic\030\002 \001(\0132\026.StrategyPacket.Tactic\022$\n"
    "\005which\030\003 \002(\0162\025.StrategyPacket.Which\032>\n\006T"
    "actic\022%\n\003tID\030\001 \002(\0162\030.StrategyPacket.Tact"
    "icID\022\r\n\005botID\030\002 \002(\005\"\241\002\n\004Play\022\022\n\016Defensiv"
    "eSteal\020\001\022\027\n\023DefenceSetPosition1\020\002\022\025\n\021Def"
    "ensiveGoToGoal\020\003\022\010\n\004None\020\004\022\017\n\013OffensePla"
    "y\020\005\022\014\n\010TestPlay\020\006\022\017\n\013SetPosition\020\007\022\025\n\021Po"
    "sitionOurStrike\020\010\022\025\n\021PositionOppStrike\020\t"
    "\022\027\n\023OffenceSetPosition1\020\n\022\017\n\013OurGoalKick"
    "\020\013\022\017\n\013OppGoalKick\020\014\022\030\n\024TieBreakerOurPena"
    "lty\020\r\022\030\n\024TieBreakerOppPenalty\020\016\"\207\002\n\010Tact"
    "icID\022\t\n\005Block\020\001\022\016\n\nChargeBall\020\002\022\r\n\tCover"
    "Goal\020\003\022\016\n\nDragToGoal\020\004\022\016\n\nDefendLine\020\005\022\017"
    "\n\013DefendPoint\020\006\022\r\n\tGoalieOur\020\007\022\r\n\tGoalie"
    "Opp\020\010\022\013\n\007MarkBot\020\t\022\014\n\010Position\020\n\022\026\n\022Posi"
    "tionForPenalty\020\013\022\024\n\020PositionForStart\020\014\022\n"
    "\n\006Defend\020\r\022\n\n\006Attack\020\016\022\t\n\005Steal\020\017\022\010\n\004Sto"
    "p\020\020\022\014\n\010Velocity\020\021\"\035\n\005Which\022\010\n\004PLAY\020\001\022\n\n\006"
    "TACTIC\020\002", 808);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "command-packet.proto", &protobuf_RegisterTypes);
  StrategyPacket::default_instance_ = new StrategyPacket();
  StrategyPacket_Tactic::default_instance_ = new StrategyPacket_Tactic();
  StrategyPacket::default_instance_->InitAsDefaultInstance();
  StrategyPacket_Tactic::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_command_2dpacket_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_command_2dpacket_2eproto {
  StaticDescriptorInitializer_command_2dpacket_2eproto() {
    protobuf_AddDesc_command_2dpacket_2eproto();
  }
} static_descriptor_initializer_command_2dpacket_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* StrategyPacket_Play_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return StrategyPacket_Play_descriptor_;
}
bool StrategyPacket_Play_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const StrategyPacket_Play StrategyPacket::DefensiveSteal;
const StrategyPacket_Play StrategyPacket::DefenceSetPosition1;
const StrategyPacket_Play StrategyPacket::DefensiveGoToGoal;
const StrategyPacket_Play StrategyPacket::None;
const StrategyPacket_Play StrategyPacket::OffensePlay;
const StrategyPacket_Play StrategyPacket::TestPlay;
const StrategyPacket_Play StrategyPacket::SetPosition;
const StrategyPacket_Play StrategyPacket::PositionOurStrike;
const StrategyPacket_Play StrategyPacket::PositionOppStrike;
const StrategyPacket_Play StrategyPacket::OffenceSetPosition1;
const StrategyPacket_Play StrategyPacket::OurGoalKick;
const StrategyPacket_Play StrategyPacket::OppGoalKick;
const StrategyPacket_Play StrategyPacket::TieBreakerOurPenalty;
const StrategyPacket_Play StrategyPacket::TieBreakerOppPenalty;
const StrategyPacket_Play StrategyPacket::Play_MIN;
const StrategyPacket_Play StrategyPacket::Play_MAX;
const int StrategyPacket::Play_ARRAYSIZE;
#endif  // _MSC_VER
const ::google::protobuf::EnumDescriptor* StrategyPacket_TacticID_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return StrategyPacket_TacticID_descriptor_;
}
bool StrategyPacket_TacticID_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const StrategyPacket_TacticID StrategyPacket::Block;
const StrategyPacket_TacticID StrategyPacket::ChargeBall;
const StrategyPacket_TacticID StrategyPacket::CoverGoal;
const StrategyPacket_TacticID StrategyPacket::DragToGoal;
const StrategyPacket_TacticID StrategyPacket::DefendLine;
const StrategyPacket_TacticID StrategyPacket::DefendPoint;
const StrategyPacket_TacticID StrategyPacket::GoalieOur;
const StrategyPacket_TacticID StrategyPacket::GoalieOpp;
const StrategyPacket_TacticID StrategyPacket::MarkBot;
const StrategyPacket_TacticID StrategyPacket::Position;
const StrategyPacket_TacticID StrategyPacket::PositionForPenalty;
const StrategyPacket_TacticID StrategyPacket::PositionForStart;
const StrategyPacket_TacticID StrategyPacket::Defend;
const StrategyPacket_TacticID StrategyPacket::Attack;
const StrategyPacket_TacticID StrategyPacket::Steal;
const StrategyPacket_TacticID StrategyPacket::Stop;
const StrategyPacket_TacticID StrategyPacket::Velocity;
const StrategyPacket_TacticID StrategyPacket::TacticID_MIN;
const StrategyPacket_TacticID StrategyPacket::TacticID_MAX;
const int StrategyPacket::TacticID_ARRAYSIZE;
#endif  // _MSC_VER
const ::google::protobuf::EnumDescriptor* StrategyPacket_Which_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return StrategyPacket_Which_descriptor_;
}
bool StrategyPacket_Which_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const StrategyPacket_Which StrategyPacket::PLAY;
const StrategyPacket_Which StrategyPacket::TACTIC;
const StrategyPacket_Which StrategyPacket::Which_MIN;
const StrategyPacket_Which StrategyPacket::Which_MAX;
const int StrategyPacket::Which_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int StrategyPacket_Tactic::kTIDFieldNumber;
const int StrategyPacket_Tactic::kBotIDFieldNumber;
#endif  // !_MSC_VER

StrategyPacket_Tactic::StrategyPacket_Tactic()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void StrategyPacket_Tactic::InitAsDefaultInstance() {
}

StrategyPacket_Tactic::StrategyPacket_Tactic(const StrategyPacket_Tactic& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void StrategyPacket_Tactic::SharedCtor() {
  _cached_size_ = 0;
  tid_ = 1;
  botid_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

StrategyPacket_Tactic::~StrategyPacket_Tactic() {
  SharedDtor();
}

void StrategyPacket_Tactic::SharedDtor() {
  if (this != default_instance_) {
  }
}

void StrategyPacket_Tactic::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* StrategyPacket_Tactic::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return StrategyPacket_Tactic_descriptor_;
}

const StrategyPacket_Tactic& StrategyPacket_Tactic::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_command_2dpacket_2eproto();
  return *default_instance_;
}

StrategyPacket_Tactic* StrategyPacket_Tactic::default_instance_ = NULL;

StrategyPacket_Tactic* StrategyPacket_Tactic::New() const {
  return new StrategyPacket_Tactic;
}

void StrategyPacket_Tactic::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    tid_ = 1;
    botid_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool StrategyPacket_Tactic::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .StrategyPacket.TacticID tID = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::StrategyPacket_TacticID_IsValid(value)) {
            set_tid(static_cast< ::StrategyPacket_TacticID >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_botID;
        break;
      }

      // required int32 botID = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_botID:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &botid_)));
          set_has_botid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void StrategyPacket_Tactic::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .StrategyPacket.TacticID tID = 1;
  if (has_tid()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->tid(), output);
  }

  // required int32 botID = 2;
  if (has_botid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->botid(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* StrategyPacket_Tactic::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .StrategyPacket.TacticID tID = 1;
  if (has_tid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->tid(), target);
  }

  // required int32 botID = 2;
  if (has_botid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->botid(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int StrategyPacket_Tactic::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .StrategyPacket.TacticID tID = 1;
    if (has_tid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->tid());
    }

    // required int32 botID = 2;
    if (has_botid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->botid());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void StrategyPacket_Tactic::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const StrategyPacket_Tactic* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const StrategyPacket_Tactic*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void StrategyPacket_Tactic::MergeFrom(const StrategyPacket_Tactic& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_tid()) {
      set_tid(from.tid());
    }
    if (from.has_botid()) {
      set_botid(from.botid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void StrategyPacket_Tactic::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void StrategyPacket_Tactic::CopyFrom(const StrategyPacket_Tactic& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool StrategyPacket_Tactic::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void StrategyPacket_Tactic::Swap(StrategyPacket_Tactic* other) {
  if (other != this) {
    std::swap(tid_, other->tid_);
    std::swap(botid_, other->botid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata StrategyPacket_Tactic::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = StrategyPacket_Tactic_descriptor_;
  metadata.reflection = StrategyPacket_Tactic_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int StrategyPacket::kPlayFieldNumber;
const int StrategyPacket::kTacticFieldNumber;
const int StrategyPacket::kWhichFieldNumber;
#endif  // !_MSC_VER

StrategyPacket::StrategyPacket()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void StrategyPacket::InitAsDefaultInstance() {
  tactic_ = const_cast< ::StrategyPacket_Tactic*>(&::StrategyPacket_Tactic::default_instance());
}

StrategyPacket::StrategyPacket(const StrategyPacket& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void StrategyPacket::SharedCtor() {
  _cached_size_ = 0;
  play_ = 1;
  tactic_ = NULL;
  which_ = 1;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

StrategyPacket::~StrategyPacket() {
  SharedDtor();
}

void StrategyPacket::SharedDtor() {
  if (this != default_instance_) {
    delete tactic_;
  }
}

void StrategyPacket::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* StrategyPacket::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return StrategyPacket_descriptor_;
}

const StrategyPacket& StrategyPacket::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_command_2dpacket_2eproto();
  return *default_instance_;
}

StrategyPacket* StrategyPacket::default_instance_ = NULL;

StrategyPacket* StrategyPacket::New() const {
  return new StrategyPacket;
}

void StrategyPacket::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    play_ = 1;
    if (has_tactic()) {
      if (tactic_ != NULL) tactic_->::StrategyPacket_Tactic::Clear();
    }
    which_ = 1;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool StrategyPacket::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .StrategyPacket.Play play = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::StrategyPacket_Play_IsValid(value)) {
            set_play(static_cast< ::StrategyPacket_Play >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_tactic;
        break;
      }

      // optional .StrategyPacket.Tactic tactic = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_tactic:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_tactic()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_which;
        break;
      }

      // required .StrategyPacket.Which which = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_which:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::StrategyPacket_Which_IsValid(value)) {
            set_which(static_cast< ::StrategyPacket_Which >(value));
          } else {
            mutable_unknown_fields()->AddVarint(3, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void StrategyPacket::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional .StrategyPacket.Play play = 1;
  if (has_play()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->play(), output);
  }

  // optional .StrategyPacket.Tactic tactic = 2;
  if (has_tactic()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->tactic(), output);
  }

  // required .StrategyPacket.Which which = 3;
  if (has_which()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->which(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* StrategyPacket::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional .StrategyPacket.Play play = 1;
  if (has_play()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->play(), target);
  }

  // optional .StrategyPacket.Tactic tactic = 2;
  if (has_tactic()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->tactic(), target);
  }

  // required .StrategyPacket.Which which = 3;
  if (has_which()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->which(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int StrategyPacket::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .StrategyPacket.Play play = 1;
    if (has_play()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->play());
    }

    // optional .StrategyPacket.Tactic tactic = 2;
    if (has_tactic()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->tactic());
    }

    // required .StrategyPacket.Which which = 3;
    if (has_which()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->which());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void StrategyPacket::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const StrategyPacket* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const StrategyPacket*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void StrategyPacket::MergeFrom(const StrategyPacket& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_play()) {
      set_play(from.play());
    }
    if (from.has_tactic()) {
      mutable_tactic()->::StrategyPacket_Tactic::MergeFrom(from.tactic());
    }
    if (from.has_which()) {
      set_which(from.which());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void StrategyPacket::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void StrategyPacket::CopyFrom(const StrategyPacket& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool StrategyPacket::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000004) != 0x00000004) return false;

  if (has_tactic()) {
    if (!this->tactic().IsInitialized()) return false;
  }
  return true;
}

void StrategyPacket::Swap(StrategyPacket* other) {
  if (other != this) {
    std::swap(play_, other->play_);
    std::swap(tactic_, other->tactic_);
    std::swap(which_, other->which_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata StrategyPacket::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = StrategyPacket_descriptor_;
  metadata.reflection = StrategyPacket_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
