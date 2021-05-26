//
//  KKImageBrowserCell.h
//  QMKKXProduct
//
//  Created by Hansen on 6/18/20.
//  Copyright © 2020 力王工作室. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef enum : NSUInteger {
    KKImageBrowserImageType,//图片
    KKImageBrowserGifType,//gif图片
    KKImageBrowserVideoType,//视频
} KKImageBrowserType;

@interface KKImageBrowserModel : NSObject
@property (assign, nonatomic) UIView *toView;//一般填imageView
@property (assign, nonatomic) KKImageBrowserType type;//默认KKImageBrowserImageType
@property (strong, nonatomic) UIImage *image;//系统image图片资源 优先显示image
@property (strong, nonatomic) NSURL *url;//根据url可以判断是否是取本地或者网络的资源

/// 快速创建model
/// @param url url
/// @param type 类型
- (instancetype)initWithUrl:(NSURL *)url type:(KKImageBrowserType) type;

/// 快速创建model
/// @param image image
- (instancetype)initWithImage:(UIImage *)image;
@end

@interface KKImageBrowserCell : UICollectionViewCell
@property (strong, nonatomic) UIScrollView *scrollView;
@property (strong, nonatomic) UIImageView *browserImageView;
@property (strong, nonatomic) KKImageBrowserModel *cellModel;
@property (weak  , nonatomic) UIView *weakBackgroundView;

//用户单击0，用户双击1，用户下滑上滑退出2
@property (copy  , nonatomic) void(^whenActionClick)(KKImageBrowserCell *cell,NSInteger index);
@end

