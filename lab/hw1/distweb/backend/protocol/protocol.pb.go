// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.31.0
// 	protoc        v4.23.4
// source: backend/protocol/protocol.proto

package protocol_update

import (
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	emptypb "google.golang.org/protobuf/types/known/emptypb"
	reflect "reflect"
	sync "sync"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

type FileChunk struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Contents    []byte `protobuf:"bytes,1,opt,name=contents,proto3" json:"contents,omitempty"`
	FileName    string `protobuf:"bytes,2,opt,name=fileName,proto3" json:"fileName,omitempty"`
	ServiceType string `protobuf:"bytes,3,opt,name=serviceType,proto3" json:"serviceType,omitempty"`
	NodeAddress string `protobuf:"bytes,4,opt,name=nodeAddress,proto3" json:"nodeAddress,omitempty"`
	DNS         string `protobuf:"bytes,5,opt,name=DNS,proto3" json:"DNS,omitempty"`
}

func (x *FileChunk) Reset() {
	*x = FileChunk{}
	if protoimpl.UnsafeEnabled {
		mi := &file_backend_protocol_protocol_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *FileChunk) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*FileChunk) ProtoMessage() {}

func (x *FileChunk) ProtoReflect() protoreflect.Message {
	mi := &file_backend_protocol_protocol_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use FileChunk.ProtoReflect.Descriptor instead.
func (*FileChunk) Descriptor() ([]byte, []int) {
	return file_backend_protocol_protocol_proto_rawDescGZIP(), []int{0}
}

func (x *FileChunk) GetContents() []byte {
	if x != nil {
		return x.Contents
	}
	return nil
}

func (x *FileChunk) GetFileName() string {
	if x != nil {
		return x.FileName
	}
	return ""
}

func (x *FileChunk) GetServiceType() string {
	if x != nil {
		return x.ServiceType
	}
	return ""
}

func (x *FileChunk) GetNodeAddress() string {
	if x != nil {
		return x.NodeAddress
	}
	return ""
}

func (x *FileChunk) GetDNS() string {
	if x != nil {
		return x.DNS
	}
	return ""
}

type FileMetadata struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	FileID   string `protobuf:"bytes,1,opt,name=fileID,proto3" json:"fileID,omitempty"`
	FileName string `protobuf:"bytes,2,opt,name=fileName,proto3" json:"fileName,omitempty"`
	FileSize string `protobuf:"bytes,3,opt,name=fileSize,proto3" json:"fileSize,omitempty"`
	Sender   string `protobuf:"bytes,4,opt,name=sender,proto3" json:"sender,omitempty"`
	Recv     string `protobuf:"bytes,5,opt,name=recv,proto3" json:"recv,omitempty"`
}

func (x *FileMetadata) Reset() {
	*x = FileMetadata{}
	if protoimpl.UnsafeEnabled {
		mi := &file_backend_protocol_protocol_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *FileMetadata) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*FileMetadata) ProtoMessage() {}

func (x *FileMetadata) ProtoReflect() protoreflect.Message {
	mi := &file_backend_protocol_protocol_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use FileMetadata.ProtoReflect.Descriptor instead.
func (*FileMetadata) Descriptor() ([]byte, []int) {
	return file_backend_protocol_protocol_proto_rawDescGZIP(), []int{1}
}

func (x *FileMetadata) GetFileID() string {
	if x != nil {
		return x.FileID
	}
	return ""
}

func (x *FileMetadata) GetFileName() string {
	if x != nil {
		return x.FileName
	}
	return ""
}

func (x *FileMetadata) GetFileSize() string {
	if x != nil {
		return x.FileSize
	}
	return ""
}

func (x *FileMetadata) GetSender() string {
	if x != nil {
		return x.Sender
	}
	return ""
}

func (x *FileMetadata) GetRecv() string {
	if x != nil {
		return x.Recv
	}
	return ""
}

// Filelist from DB
type FileInfoList struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Filelist []*FileInfoList_FileInfo `protobuf:"bytes,3,rep,name=filelist,proto3" json:"filelist,omitempty"`
}

func (x *FileInfoList) Reset() {
	*x = FileInfoList{}
	if protoimpl.UnsafeEnabled {
		mi := &file_backend_protocol_protocol_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *FileInfoList) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*FileInfoList) ProtoMessage() {}

func (x *FileInfoList) ProtoReflect() protoreflect.Message {
	mi := &file_backend_protocol_protocol_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use FileInfoList.ProtoReflect.Descriptor instead.
func (*FileInfoList) Descriptor() ([]byte, []int) {
	return file_backend_protocol_protocol_proto_rawDescGZIP(), []int{2}
}

func (x *FileInfoList) GetFilelist() []*FileInfoList_FileInfo {
	if x != nil {
		return x.Filelist
	}
	return nil
}

type DispatchInfo struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Sender string `protobuf:"bytes,1,opt,name=sender,proto3" json:"sender,omitempty"`
	Recv   string `protobuf:"bytes,2,opt,name=recv,proto3" json:"recv,omitempty"`
}

func (x *DispatchInfo) Reset() {
	*x = DispatchInfo{}
	if protoimpl.UnsafeEnabled {
		mi := &file_backend_protocol_protocol_proto_msgTypes[3]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *DispatchInfo) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*DispatchInfo) ProtoMessage() {}

func (x *DispatchInfo) ProtoReflect() protoreflect.Message {
	mi := &file_backend_protocol_protocol_proto_msgTypes[3]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use DispatchInfo.ProtoReflect.Descriptor instead.
func (*DispatchInfo) Descriptor() ([]byte, []int) {
	return file_backend_protocol_protocol_proto_rawDescGZIP(), []int{3}
}

func (x *DispatchInfo) GetSender() string {
	if x != nil {
		return x.Sender
	}
	return ""
}

func (x *DispatchInfo) GetRecv() string {
	if x != nil {
		return x.Recv
	}
	return ""
}

type FileInfoList_FileInfo struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	FileID   string `protobuf:"bytes,1,opt,name=fileID,proto3" json:"fileID,omitempty"`
	FileName string `protobuf:"bytes,2,opt,name=fileName,proto3" json:"fileName,omitempty"`
	FileSize string `protobuf:"bytes,3,opt,name=fileSize,proto3" json:"fileSize,omitempty"`
}

func (x *FileInfoList_FileInfo) Reset() {
	*x = FileInfoList_FileInfo{}
	if protoimpl.UnsafeEnabled {
		mi := &file_backend_protocol_protocol_proto_msgTypes[4]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *FileInfoList_FileInfo) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*FileInfoList_FileInfo) ProtoMessage() {}

func (x *FileInfoList_FileInfo) ProtoReflect() protoreflect.Message {
	mi := &file_backend_protocol_protocol_proto_msgTypes[4]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use FileInfoList_FileInfo.ProtoReflect.Descriptor instead.
func (*FileInfoList_FileInfo) Descriptor() ([]byte, []int) {
	return file_backend_protocol_protocol_proto_rawDescGZIP(), []int{2, 0}
}

func (x *FileInfoList_FileInfo) GetFileID() string {
	if x != nil {
		return x.FileID
	}
	return ""
}

func (x *FileInfoList_FileInfo) GetFileName() string {
	if x != nil {
		return x.FileName
	}
	return ""
}

func (x *FileInfoList_FileInfo) GetFileSize() string {
	if x != nil {
		return x.FileSize
	}
	return ""
}

var File_backend_protocol_protocol_proto protoreflect.FileDescriptor

var file_backend_protocol_protocol_proto_rawDesc = []byte{
	0x0a, 0x1f, 0x62, 0x61, 0x63, 0x6b, 0x65, 0x6e, 0x64, 0x2f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x63,
	0x6f, 0x6c, 0x2f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x63, 0x6f, 0x6c, 0x2e, 0x70, 0x72, 0x6f, 0x74,
	0x6f, 0x12, 0x08, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x63, 0x6f, 0x6c, 0x1a, 0x1b, 0x67, 0x6f, 0x6f,
	0x67, 0x6c, 0x65, 0x2f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x62, 0x75, 0x66, 0x2f, 0x65, 0x6d, 0x70,
	0x74, 0x79, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x22, 0x99, 0x01, 0x0a, 0x09, 0x46, 0x69, 0x6c,
	0x65, 0x43, 0x68, 0x75, 0x6e, 0x6b, 0x12, 0x1a, 0x0a, 0x08, 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x6e,
	0x74, 0x73, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0c, 0x52, 0x08, 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x6e,
	0x74, 0x73, 0x12, 0x1a, 0x0a, 0x08, 0x66, 0x69, 0x6c, 0x65, 0x4e, 0x61, 0x6d, 0x65, 0x18, 0x02,
	0x20, 0x01, 0x28, 0x09, 0x52, 0x08, 0x66, 0x69, 0x6c, 0x65, 0x4e, 0x61, 0x6d, 0x65, 0x12, 0x20,
	0x0a, 0x0b, 0x73, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x54, 0x79, 0x70, 0x65, 0x18, 0x03, 0x20,
	0x01, 0x28, 0x09, 0x52, 0x0b, 0x73, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x54, 0x79, 0x70, 0x65,
	0x12, 0x20, 0x0a, 0x0b, 0x6e, 0x6f, 0x64, 0x65, 0x41, 0x64, 0x64, 0x72, 0x65, 0x73, 0x73, 0x18,
	0x04, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0b, 0x6e, 0x6f, 0x64, 0x65, 0x41, 0x64, 0x64, 0x72, 0x65,
	0x73, 0x73, 0x12, 0x10, 0x0a, 0x03, 0x44, 0x4e, 0x53, 0x18, 0x05, 0x20, 0x01, 0x28, 0x09, 0x52,
	0x03, 0x44, 0x4e, 0x53, 0x22, 0x8a, 0x01, 0x0a, 0x0c, 0x46, 0x69, 0x6c, 0x65, 0x4d, 0x65, 0x74,
	0x61, 0x64, 0x61, 0x74, 0x61, 0x12, 0x16, 0x0a, 0x06, 0x66, 0x69, 0x6c, 0x65, 0x49, 0x44, 0x18,
	0x01, 0x20, 0x01, 0x28, 0x09, 0x52, 0x06, 0x66, 0x69, 0x6c, 0x65, 0x49, 0x44, 0x12, 0x1a, 0x0a,
	0x08, 0x66, 0x69, 0x6c, 0x65, 0x4e, 0x61, 0x6d, 0x65, 0x18, 0x02, 0x20, 0x01, 0x28, 0x09, 0x52,
	0x08, 0x66, 0x69, 0x6c, 0x65, 0x4e, 0x61, 0x6d, 0x65, 0x12, 0x1a, 0x0a, 0x08, 0x66, 0x69, 0x6c,
	0x65, 0x53, 0x69, 0x7a, 0x65, 0x18, 0x03, 0x20, 0x01, 0x28, 0x09, 0x52, 0x08, 0x66, 0x69, 0x6c,
	0x65, 0x53, 0x69, 0x7a, 0x65, 0x12, 0x16, 0x0a, 0x06, 0x73, 0x65, 0x6e, 0x64, 0x65, 0x72, 0x18,
	0x04, 0x20, 0x01, 0x28, 0x09, 0x52, 0x06, 0x73, 0x65, 0x6e, 0x64, 0x65, 0x72, 0x12, 0x12, 0x0a,
	0x04, 0x72, 0x65, 0x63, 0x76, 0x18, 0x05, 0x20, 0x01, 0x28, 0x09, 0x52, 0x04, 0x72, 0x65, 0x63,
	0x76, 0x22, 0xa7, 0x01, 0x0a, 0x0c, 0x46, 0x69, 0x6c, 0x65, 0x49, 0x6e, 0x66, 0x6f, 0x4c, 0x69,
	0x73, 0x74, 0x12, 0x3b, 0x0a, 0x08, 0x66, 0x69, 0x6c, 0x65, 0x6c, 0x69, 0x73, 0x74, 0x18, 0x03,
	0x20, 0x03, 0x28, 0x0b, 0x32, 0x1f, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x63, 0x6f, 0x6c, 0x2e,
	0x46, 0x69, 0x6c, 0x65, 0x49, 0x6e, 0x66, 0x6f, 0x4c, 0x69, 0x73, 0x74, 0x2e, 0x46, 0x69, 0x6c,
	0x65, 0x49, 0x6e, 0x66, 0x6f, 0x52, 0x08, 0x66, 0x69, 0x6c, 0x65, 0x6c, 0x69, 0x73, 0x74, 0x1a,
	0x5a, 0x0a, 0x08, 0x46, 0x69, 0x6c, 0x65, 0x49, 0x6e, 0x66, 0x6f, 0x12, 0x16, 0x0a, 0x06, 0x66,
	0x69, 0x6c, 0x65, 0x49, 0x44, 0x18, 0x01, 0x20, 0x01, 0x28, 0x09, 0x52, 0x06, 0x66, 0x69, 0x6c,
	0x65, 0x49, 0x44, 0x12, 0x1a, 0x0a, 0x08, 0x66, 0x69, 0x6c, 0x65, 0x4e, 0x61, 0x6d, 0x65, 0x18,
	0x02, 0x20, 0x01, 0x28, 0x09, 0x52, 0x08, 0x66, 0x69, 0x6c, 0x65, 0x4e, 0x61, 0x6d, 0x65, 0x12,
	0x1a, 0x0a, 0x08, 0x66, 0x69, 0x6c, 0x65, 0x53, 0x69, 0x7a, 0x65, 0x18, 0x03, 0x20, 0x01, 0x28,
	0x09, 0x52, 0x08, 0x66, 0x69, 0x6c, 0x65, 0x53, 0x69, 0x7a, 0x65, 0x22, 0x3a, 0x0a, 0x0c, 0x44,
	0x69, 0x73, 0x70, 0x61, 0x74, 0x63, 0x68, 0x49, 0x6e, 0x66, 0x6f, 0x12, 0x16, 0x0a, 0x06, 0x73,
	0x65, 0x6e, 0x64, 0x65, 0x72, 0x18, 0x01, 0x20, 0x01, 0x28, 0x09, 0x52, 0x06, 0x73, 0x65, 0x6e,
	0x64, 0x65, 0x72, 0x12, 0x12, 0x0a, 0x04, 0x72, 0x65, 0x63, 0x76, 0x18, 0x02, 0x20, 0x01, 0x28,
	0x09, 0x52, 0x04, 0x72, 0x65, 0x63, 0x76, 0x32, 0xcb, 0x01, 0x0a, 0x13, 0x46, 0x69, 0x6c, 0x65,
	0x54, 0x72, 0x61, 0x6e, 0x73, 0x66, 0x65, 0x72, 0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x12,
	0x38, 0x0a, 0x07, 0x47, 0x65, 0x74, 0x46, 0x69, 0x6c, 0x65, 0x12, 0x16, 0x2e, 0x70, 0x72, 0x6f,
	0x74, 0x6f, 0x63, 0x6f, 0x6c, 0x2e, 0x46, 0x69, 0x6c, 0x65, 0x4d, 0x65, 0x74, 0x61, 0x64, 0x61,
	0x74, 0x61, 0x1a, 0x13, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x63, 0x6f, 0x6c, 0x2e, 0x46, 0x69,
	0x6c, 0x65, 0x43, 0x68, 0x75, 0x6e, 0x6b, 0x30, 0x01, 0x12, 0x3b, 0x0a, 0x0a, 0x55, 0x70, 0x6c,
	0x6f, 0x61, 0x64, 0x46, 0x69, 0x6c, 0x65, 0x12, 0x13, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x63,
	0x6f, 0x6c, 0x2e, 0x46, 0x69, 0x6c, 0x65, 0x43, 0x68, 0x75, 0x6e, 0x6b, 0x1a, 0x16, 0x2e, 0x67,
	0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x62, 0x75, 0x66, 0x2e, 0x45,
	0x6d, 0x70, 0x74, 0x79, 0x28, 0x01, 0x12, 0x3d, 0x0a, 0x0b, 0x47, 0x65, 0x74, 0x46, 0x69, 0x6c,
	0x65, 0x4c, 0x69, 0x73, 0x74, 0x12, 0x16, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x63, 0x6f, 0x6c,
	0x2e, 0x44, 0x69, 0x73, 0x70, 0x61, 0x74, 0x63, 0x68, 0x49, 0x6e, 0x66, 0x6f, 0x1a, 0x16, 0x2e,
	0x70, 0x72, 0x6f, 0x74, 0x6f, 0x63, 0x6f, 0x6c, 0x2e, 0x46, 0x69, 0x6c, 0x65, 0x49, 0x6e, 0x66,
	0x6f, 0x4c, 0x69, 0x73, 0x74, 0x42, 0x13, 0x5a, 0x11, 0x2e, 0x2f, 0x70, 0x72, 0x6f, 0x74, 0x6f,
	0x63, 0x6f, 0x6c, 0x5f, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74,
	0x6f, 0x33,
}

var (
	file_backend_protocol_protocol_proto_rawDescOnce sync.Once
	file_backend_protocol_protocol_proto_rawDescData = file_backend_protocol_protocol_proto_rawDesc
)

func file_backend_protocol_protocol_proto_rawDescGZIP() []byte {
	file_backend_protocol_protocol_proto_rawDescOnce.Do(func() {
		file_backend_protocol_protocol_proto_rawDescData = protoimpl.X.CompressGZIP(file_backend_protocol_protocol_proto_rawDescData)
	})
	return file_backend_protocol_protocol_proto_rawDescData
}

var file_backend_protocol_protocol_proto_msgTypes = make([]protoimpl.MessageInfo, 5)
var file_backend_protocol_protocol_proto_goTypes = []interface{}{
	(*FileChunk)(nil),             // 0: protocol.FileChunk
	(*FileMetadata)(nil),          // 1: protocol.FileMetadata
	(*FileInfoList)(nil),          // 2: protocol.FileInfoList
	(*DispatchInfo)(nil),          // 3: protocol.DispatchInfo
	(*FileInfoList_FileInfo)(nil), // 4: protocol.FileInfoList.FileInfo
	(*emptypb.Empty)(nil),         // 5: google.protobuf.Empty
}
var file_backend_protocol_protocol_proto_depIdxs = []int32{
	4, // 0: protocol.FileInfoList.filelist:type_name -> protocol.FileInfoList.FileInfo
	1, // 1: protocol.FileTransferService.GetFile:input_type -> protocol.FileMetadata
	0, // 2: protocol.FileTransferService.UploadFile:input_type -> protocol.FileChunk
	3, // 3: protocol.FileTransferService.GetFileList:input_type -> protocol.DispatchInfo
	0, // 4: protocol.FileTransferService.GetFile:output_type -> protocol.FileChunk
	5, // 5: protocol.FileTransferService.UploadFile:output_type -> google.protobuf.Empty
	2, // 6: protocol.FileTransferService.GetFileList:output_type -> protocol.FileInfoList
	4, // [4:7] is the sub-list for method output_type
	1, // [1:4] is the sub-list for method input_type
	1, // [1:1] is the sub-list for extension type_name
	1, // [1:1] is the sub-list for extension extendee
	0, // [0:1] is the sub-list for field type_name
}

func init() { file_backend_protocol_protocol_proto_init() }
func file_backend_protocol_protocol_proto_init() {
	if File_backend_protocol_protocol_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_backend_protocol_protocol_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*FileChunk); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_backend_protocol_protocol_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*FileMetadata); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_backend_protocol_protocol_proto_msgTypes[2].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*FileInfoList); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_backend_protocol_protocol_proto_msgTypes[3].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*DispatchInfo); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_backend_protocol_protocol_proto_msgTypes[4].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*FileInfoList_FileInfo); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
	}
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: file_backend_protocol_protocol_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   5,
			NumExtensions: 0,
			NumServices:   1,
		},
		GoTypes:           file_backend_protocol_protocol_proto_goTypes,
		DependencyIndexes: file_backend_protocol_protocol_proto_depIdxs,
		MessageInfos:      file_backend_protocol_protocol_proto_msgTypes,
	}.Build()
	File_backend_protocol_protocol_proto = out.File
	file_backend_protocol_protocol_proto_rawDesc = nil
	file_backend_protocol_protocol_proto_goTypes = nil
	file_backend_protocol_protocol_proto_depIdxs = nil
}
