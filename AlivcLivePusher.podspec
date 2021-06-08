Pod::Spec.new do |s|

  s.name         = "AlivcLivePusher"
  s.version      = "4.1.0"
  s.summary      = "AlivcLivePusher_iOS"
  s.description  = <<-DESC
                   It's an SDK for aliyun video vodplay, which implement by Objective-C.
                   DESC
  s.homepage     = "https://github.com/aliyunvideo/AliyunLivePusher_iOS"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "aliyunvideo" => "videosdk@service.aliyun.com"}
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/aliyunvideo/AliyunLivePusher_iOS.git", :tag => "#{s.version}" }

  s.subspec 'AlivcLivePusher' do |pushersdk|
  pushersdk.vendored_frameworks = 'RtsSDK.framework','queen.framework','pixelai.framework','opencv2.framework','MNN.framework','FaceDetection.framework','Face3D.framework','AlivcLibArtp.framework','AlivcLivePusher.framework','AlivcLibRtmp.framework','AlivcLibBeauty.framework','AlivcLibFace.framework'
  pushersdk.resource = 'AlivcLibFaceResource.bundle'
# pushersdk.frameworks = 'MediaPlayer','CoreGraphics'
  end

end
