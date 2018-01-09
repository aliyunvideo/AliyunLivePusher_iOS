Pod::Spec.new do |s|

  s.name         = "AlivcLivePusher"
  s.version      = "2.1.0"
  s.summary      = "AlivcLivePusher_iOS"
  s.description  = <<-DESC
                   It's an SDK for aliyun video vodplay, which implement by Objective-C.
                   DESC
  s.homepage     = "https://github.com/aliyunvideo/AliyunLivePusher_iOS"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "aliyunvideo" => "videosdk@service.aliyun.com"}
  s.platform     = :ios, "8.0"
  s.source       = { :git => "http://github.com/aliyunvideo/AliyunLivePusher_iOS.git", :tag => "#{s.version}" }

# 不带播放器
  s.subspec 'AlivcLivePusher' do |pushersdk|
  pushersdk.vendored_frameworks = 'AlivcLivePusher.framework','AlivcLibRtmp.framework'
  pushersdk.resource = 'AlivcLibFaceResource.bundle'
# pushersdk.frameworks = 'MediaPlayer','CoreGraphics'
  end

# 带播放器
  s.subspec 'AlivcLivePusherWithPlayer' do |pusher_playersdk|
  pusher_playersdk.vendored_frameworks = 'AlivcLivePusher_Player.framework','AlivcLibRtmp.framework'
  pusher_playersdk.resource = 'AlivcLibFaceResource.bundle'
  end

end