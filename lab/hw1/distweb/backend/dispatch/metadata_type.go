package dispatch

type FileUploadRequestMetadata struct {
	RecvAddress   string
	SenderAddress string
	FilePath      string
	FileName      string
}

type FileDownloadRequestMetadata struct {
	RecvAddress   string
	SenderAddress string
	FilePath      string
	FileName      string
	FileID        string
	// FileSize      string
}
