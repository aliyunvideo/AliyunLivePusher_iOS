Pod::Spec.new do |s|

  s.name         = "AlivcLivePusher"
  s.version      = "6.2.0"
  s.summary      = "AlivcLivePusher_iOS"
  s.description  = <<-DESC
                   It's an SDK for aliyun video vodplay, which implement by Objective-C.
                   DESC
  s.homepage     = "https://github.com/aliyunvideo/AliyunLivePusher_iOS"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "aliyunvideo" => "videosdk@service.aliyun.com"}
  s.platform     = :ios
  s.platform     = :ios, "9.0"
  s.source       = { :git => "https://github.com/aliyunvideo/AliyunLivePusher_iOS.git", :tag => "#{s.version}" }



  s.subspec 'AlivcLivePusher' do |pushersdk|
  pushersdk.vendored_frameworks = 'AlivcLivePusher.framework','AlivcLibReplayKitExt.framework'
  pushersdk.frameworks = "CoreVideo","OpenGLES","AVFoundation","CoreMedia","VideoToolbox","AudioToolbox"
# pushersdk.frameworks = 'MediaPlayer','CoreGraphics'
  end

end
