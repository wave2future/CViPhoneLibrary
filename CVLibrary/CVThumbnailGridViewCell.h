//
//  ThumbnailViewCell.h
//  ColoringBook
//
//  Created by Kerem Karatal on 1/23/09.
//  Copyright 2009 Coding Ventures. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CVImage.h"

@protocol CVThumbnailGridViewCellDelegate;

@interface CVThumbnailGridViewCell : UIView {
@private
	id delegate_;
	NSIndexPath *indexPath_;
	UIImageView *thumbnailImageView_;
    CGPoint touchLocation_; // Location of touch in own coordinates (stays constant during dragging).
    BOOL dragging_, isInEditMode_;
    CGRect home_;
    
    CVImage *cachedImage_;
}

@property (nonatomic, assign) id<CVThumbnailGridViewCellDelegate> delegate;
@property (nonatomic, retain) NSIndexPath *indexPath;
@property (nonatomic, assign) CGRect home;
@property (nonatomic, assign) CGPoint touchLocation;
@property (nonatomic, assign) CVImage *cachedImage;

- (id) initWithFrame:(CGRect)frame reuseIdentifier:(NSString *) identifier;
- (void) setImage:(UIImage *) image;
- (void) goHome;
- (void) moveByOffset:(CGPoint)offset;
@end

@protocol CVThumbnailGridViewCellDelegate <NSObject>
@required
- (BOOL) isInEditMode;

@optional
- (void)thumbnailGridViewCellWasTapped:(CVThumbnailGridViewCell *) cell;
- (void)thumbnailGridViewCellStartedTracking:(CVThumbnailGridViewCell *) cell;
- (void)thumbnailGridViewCellMoved:(CVThumbnailGridViewCell *) cell;
- (void)thumbnailGridViewCellStoppedTracking:(CVThumbnailGridViewCell *) cell;

@end
