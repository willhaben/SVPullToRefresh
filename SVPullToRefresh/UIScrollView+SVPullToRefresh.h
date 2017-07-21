//
// UIScrollView+SVPullToRefresh.h
//
// Created by Sam Vermette on 23.04.12.
// Copyright (c) 2012 samvermette.com. All rights reserved.
//
// https://github.com/samvermette/SVPullToRefresh
//

#import <UIKit/UIKit.h>
#import <AvailabilityMacros.h>


@class SVPullToRefreshView;

@interface UIScrollView (SVPullToRefresh)

- (void)addPullToRefreshWithActionHandler:(nullable void (^)(void))actionHandler;
- (void)triggerPullToRefresh;

@property (nullable, nonatomic, strong, readonly) SVPullToRefreshView *pullToRefreshView;
@property (nonatomic, assign) BOOL showsPullToRefresh;

@end


enum {
    SVPullToRefreshStateStopped = 0,
    SVPullToRefreshStateTriggered,
    SVPullToRefreshStateLoading,
    SVPullToRefreshStateAll = 10
};

typedef NSUInteger SVPullToRefreshState;

@interface SVPullToRefreshView : UIView

@property (nonnull, nonatomic, strong) UIColor *arrowColor;
@property (nonnull, nonatomic, strong) UIColor *textColor;
@property (nonnull, nonatomic, strong, readonly) UILabel *titleLabel;
@property (nonnull, nonatomic, strong, readonly) UILabel *subtitleLabel;
@property (nonatomic, readwrite) UIActivityIndicatorViewStyle activityIndicatorViewStyle;

@property (nonatomic, readonly) SVPullToRefreshState state;

- (void)setTitle:(nonnull NSString *)title forState:(SVPullToRefreshState)state;
- (void)setSubtitle:(nonnull NSString *)subtitle forState:(SVPullToRefreshState)state;
- (void)setCustomView:(nullable UIView *)view forState:(SVPullToRefreshState)state;
- (void)updateOriginalContentInset:(UIEdgeInsets)newOriginalContentInset;

- (void)startAnimating;
- (void)stopAnimating;

// deprecated; use setSubtitle:forState: instead
@property (nonnull, nonatomic, strong, readonly) UILabel *dateLabel DEPRECATED_ATTRIBUTE;
@property (nonnull, nonatomic, strong) NSDate *lastUpdatedDate DEPRECATED_ATTRIBUTE;
@property (nonnull, nonatomic, strong) NSDateFormatter *dateFormatter DEPRECATED_ATTRIBUTE;

// deprecated; use [self.scrollView triggerPullToRefresh] instead
- (void)triggerRefresh DEPRECATED_ATTRIBUTE;

@end
