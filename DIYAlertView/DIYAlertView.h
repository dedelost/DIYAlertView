//
//  DIYAlertView.h
//  DIYAlertView
//
//  Created by 路海涛 on 2016/11/17.
//  Copyright © 2016年 路海涛. All rights reserved.
//
//  Lincesed under The MIT License (MIT)
//  http://opensource.org/licenses/MIT
//

#import <UIKit/UIKit.h>

@protocol DIYAlertViewDelegate

- (void)customIOS7dialogButtonTouchUpInside:(id)alertView
                       clickedButtonAtIndex:(NSInteger)buttonIndex;

@end

@interface DIYAlertView : UIView <DIYAlertViewDelegate>

@property(nonatomic, retain)
    UIView *parentView; // The parent view this 'dialog' is attached to
@property(nonatomic, retain) UIView *dialogView; // Dialog's container view
@property(nonatomic, retain) UIView
    *containerView; // Container within the dialog (place your ui elements here)

@property(nonatomic, assign) id<DIYAlertViewDelegate> delegate;
@property(nonatomic, retain) NSArray *buttonTitles;
@property(nonatomic, assign) BOOL useMotionEffects;

@property(copy) void (^onButtonTouchUpInside)
    (DIYAlertView *alertView, int buttonIndex);

- (id)init;

/*!
 DEPRECATED: Use the [CustomIOSAlertView init] method without passing a parent
 view.
 */
- (id)initWithParentView:(UIView *)_parentView __attribute__((deprecated));

- (void)show;
- (void)close;

- (void)customIOS7dialogButtonTouchUpInside:(id)sender;
- (void)setOnButtonTouchUpInside:
    (void (^)(DIYAlertView *alertView, int buttonIndex))onButtonTouchUpInside;

- (void)deviceOrientationDidChange:(NSNotification *)notification;
- (void)dealloc;

@end
