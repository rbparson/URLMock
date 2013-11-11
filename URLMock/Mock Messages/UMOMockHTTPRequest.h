//
//  UMOMockHTTPRequest.h
//  URLMock
//
//  Created by Prachi Gauriar on 11/8/2013.
//  Copyright (c) 2013 Prachi Gauriar. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <Foundation/Foundation.h>
#import <URLMock/UMOMockHTTPMessage.h>

#pragma mark Constants

extern NSString *const kUMOMockHTTPRequestDeleteMethod;
extern NSString *const kUMOMockHTTPRequestGetMethod;
extern NSString *const kUMOMockHTTPRequestHeadMethod;
extern NSString *const kUMOMockHTTPRequestPatchMethod;
extern NSString *const kUMOMockHTTPRequestPostMethod;
extern NSString *const kUMOMockHTTPRequestPutMethod;


#pragma mark -

@class UMOMockHTTPResponse;

@interface UMOMockHTTPRequest : UMOMockHTTPMessage

@property (readonly, copy, nonatomic) NSString *HTTPMethod;
@property (readonly, strong, nonatomic) NSURL *URL;
@property (readonly, strong, nonatomic) NSURL *canonicalURL;
@property (readwrite, strong, nonatomic) UMOMockHTTPResponse *response;

- (instancetype)initWithHTTPMethod:(NSString *)method URL:(NSURL *)URL;

+ (instancetype)mockDeleteRequestWithURLString:(NSString *)string;
+ (instancetype)mockGetRequestWithURLString:(NSString *)string;
+ (instancetype)mockHeadRequestWithURLString:(NSString *)string;
+ (instancetype)mockPatchRequestWithURLString:(NSString *)string;
+ (instancetype)mockPostRequestWithURLString:(NSString *)string;
+ (instancetype)mockPutRequestWithURLString:(NSString *)string;

- (NSDictionary *)parametersFromURLEncodedBody;
- (void)setBodyByURLEncodingParameters:(NSDictionary *)parameters;

- (BOOL)bodyMatchesBodyOfURLRequest:(NSURLRequest *)request;
- (BOOL)matchesURLRequest:(NSURLRequest *)request;

@end
